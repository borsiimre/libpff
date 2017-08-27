/*
 * Library DEFLATE decompression testing program
 *
 * Copyright (C) 2008-2017, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <memory.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "pff_test_libcerror.h"
#include "pff_test_libcnotify.h"
#include "pff_test_libpff.h"
#include "pff_test_macros.h"
#include "pff_test_unused.h"

#include "../libpff/libpff_deflate.h"

/* Define to make pff_test_deflate generate verbose output
#define PFF_TEST_DEFLATE
 */

uint8_t pff_test_deflate_compressed_byte_stream[ 2627 ] = {
	0x78, 0xda, 0xbd, 0x59, 0x6d, 0x8f, 0xdb, 0xb8, 0x11, 0xfe, 0x7c, 0xfa, 0x15, 0xc4, 0x7e, 0xb9,
	0x5d, 0xc0, 0x75, 0x5e, 0x7b, 0x45, 0x0f, 0x45, 0x81, 0xed, 0xde, 0x26, 0xdd, 0x62, 0x2f, 0x0d,
	0xb2, 0x97, 0x16, 0xfd, 0x48, 0x4b, 0xb4, 0xcd, 0x46, 0x12, 0x5d, 0x52, 0x5a, 0xc7, 0xfd, 0xf5,
	0x7d, 0x66, 0x86, 0x94, 0x28, 0xd9, 0xde, 0xec, 0xe1, 0x80, 0x06, 0x38, 0x5c, 0x62, 0x93, 0xc3,
	0x79, 0x7d, 0xe6, 0x99, 0xf1, 0x77, 0xdf, 0x29, 0xa5, 0xde, 0x7f, 0xf8, 0xac, 0xee, 0x6f, 0x1f,
	0x1e, 0x6e, 0x3f, 0xa9, 0xf7, 0xb7, 0x1f, 0x6e, 0x3f, 0x5d, 0xdf, 0xab, 0x8f, 0x9f, 0xff, 0x72,
	0x7f, 0x77, 0xa3, 0xf0, 0xdf, 0xed, 0x87, 0x87, 0xdb, 0x42, 0x9d, 0xfe, 0xf3, 0x0f, 0xe3, 0x83,
	0x75, 0xad, 0x7a, 0xb3, 0x50, 0xaf, 0xff, 0xa8, 0xfe, 0xd6, 0xb7, 0x46, 0xbd, 0x7e, 0xf9, 0xf2,
	0x0f, 0x45, 0xa1, 0x6e, 0xdc, 0xee, 0xe0, 0xed, 0x66, 0xdb, 0xa9, 0xcb, 0x9b, 0x2b, 0xfe, 0x50,
	0xbd, 0xf3, 0xc6, 0xa8, 0x07, 0xb7, 0xee, 0xf6, 0xda, 0x1b, 0xf5, 0xce, 0xf5, 0x6d, 0xa5, 0x3b,
	0xdc, 0x5e, 0xa8, 0xbb, 0xb6, 0x5c, 0xaa, 0x3f, 0x6d, 0xbb, 0x6e, 0xf7, 0xe3, 0x8b, 0x17, 0xeb,
	0xb0, 0x5e, 0x3a, 0xbf, 0x79, 0xf1, 0xe7, 0x42, 0xdd, 0x3e, 0x1a, 0x7f, 0x70, 0x10, 0x6a, 0x83,
	0xda, 0x19, 0xdf, 0xd8, 0xae, 0x33, 0x95, 0xea, 0x9c, 0x2a, 0x21, 0x5d, 0xe9, 0xb6, 0x52, 0x95,
	0x0d, 0x9d, 0xb7, 0xab, 0xbe, 0x33, 0x0a, 0x67, 0x57, 0x90, 0xd7, 0xd0, 0x97, 0xd6, 0x84, 0x42,
	0xb9, 0xb5, 0xea, 0xb6, 0xb8, 0x59, 0xdb, 0xd2, 0xb4, 0xc1, 0xa8, 0xca, 0x95, 0x7d, 0x63, 0xda,
	0x6e, 0xa1, 0x70, 0x5e, 0x95, 0x5b, 0xdd, 0x6e, 0x6c, 0xbb, 0x51, 0xb6, 0x23, 0xf1, 0xad, 0xeb,
	0x94, 0xae, 0x6b, 0xb7, 0x37, 0xd5, 0xb2, 0x80, 0xfe, 0xea, 0x17, 0xba, 0xfa, 0x18, 0xed, 0x63,
	0x51, 0x46, 0xfc, 0x64, 0x42, 0x30, 0x5e, 0xbd, 0x37, 0xad, 0xf1, 0xba, 0x56, 0x1f, 0xfb, 0x15,
	0xe4, 0xab, 0xfb, 0xf8, 0x86, 0x6d, 0x4b, 0xe7, 0x77, 0xce, 0xeb, 0x0e, 0x1a, 0xd0, 0x95, 0x0e,
	0x6a, 0x07, 0x56, 0xb5, 0x74, 0x6d, 0x65, 0xc9, 0xde, 0x40, 0xe2, 0x92, 0xe4, 0x37, 0xb9, 0xec,
	0xa9, 0xd0, 0x22, 0x0a, 0x5d, 0xa8, 0xd0, 0xef, 0x76, 0xb5, 0x21, 0xdd, 0x61, 0xfe, 0xea, 0xc0,
	0xe7, 0x75, 0x25, 0xd2, 0x70, 0x9c, 0x5d, 0x13, 0x02, 0x8b, 0xae, 0xe1, 0x10, 0x3a, 0x64, 0x60,
	0xca, 0x92, 0xec, 0x78, 0xb9, 0x54, 0xd7, 0xe3, 0xd1, 0x9f, 0xcc, 0xda, 0xb6, 0xa2, 0xc5, 0x52,
	0xd1, 0xd7, 0xd7, 0x41, 0xf5, 0x01, 0x17, 0xb6, 0xc6, 0x1b, 0x8b, 0x50, 0x5c, 0xb0, 0xcb, 0xe2,
	0xcb, 0x17, 0xca, 0x9b, 0x35, 0x14, 0x25, 0x97, 0x9f, 0x54, 0x58, 0x9c, 0x51, 0x9c, 0x76, 0xc6,
	0x82, 0xcd, 0xa6, 0xa3, 0x17, 0x6c, 0xdc, 0xc7, 0xfb, 0x6f, 0xc9, 0x3b, 0x23, 0x88, 0xed, 0xb8,
	0xf8, 0x05, 0x67, 0xee, 0xed, 0xca, 0x6b, 0x7f, 0xc8, 0xe5, 0x68, 0x38, 0x16, 0xb2, 0x60, 0xc2,
	0xde, 0xf9, 0x2f, 0x6a, 0x43, 0xff, 0x68, 0x93, 0x9b, 0x46, 0x53, 0x16, 0x85, 0xc3, 0x23, 0x1e,
	0x9f, 0xe9, 0x16, 0x7a, 0xa9, 0x6b, 0x78, 0xd4, 0x96, 0x9c, 0x7f, 0xca, 0x79, 0x48, 0xb9, 0x71,
	0xcd, 0xca, 0xd2, 0xc5, 0x7f, 0x92, 0x18, 0x1d, 0x54, 0x45, 0xae, 0x9a, 0xb8, 0xf2, 0xba, 0x55,
	0x17, 0xd9, 0xbd, 0x0b, 0xca, 0x1b, 0xdd, 0x1e, 0xe4, 0x61, 0x08, 0xee, 0x54, 0xa3, 0xbf, 0x18,
	0x76, 0x28, 0x19, 0x85, 0x57, 0x2c, 0x22, 0xe6, 0xd7, 0xba, 0x34, 0x6a, 0xe7, 0xdd, 0xa3, 0xad,
	0x4c, 0x55, 0xc4, 0xf0, 0x45, 0x4b, 0x24, 0x17, 0xf7, 0x5b, 0x5b, 0x6e, 0x53, 0x16, 0xb2, 0x9e,
	0x7b, 0x0b, 0x19, 0x2b, 0x4d, 0x91, 0x81, 0x82, 0xd9, 0x85, 0x65, 0x21, 0x21, 0x44, 0xe2, 0x6a,
	0xe4, 0xc5, 0xaa, 0xac, 0x75, 0xe0, 0x84, 0x82, 0x1f, 0xf8, 0xaf, 0x83, 0xda, 0x93, 0x77, 0x48,
	0x78, 0x65, 0x90, 0x42, 0x15, 0x0e, 0x36, 0xae, 0x32, 0x05, 0xae, 0xf4, 0x81, 0xc5, 0x9c, 0x52,
	0x73, 0x76, 0x5d, 0xcc, 0x57, 0x17, 0x13, 0x27, 0x89, 0xfd, 0x62, 0x3d, 0xee, 0x55, 0x7d, 0x29,
	0xf7, 0x4a, 0x3e, 0x44, 0xa2, 0xe1, 0xd8, 0xda, 0xb6, 0x5f, 0xe4, 0x95, 0x22, 0x77, 0xf9, 0xde,
	0x76, 0xdb, 0xc9, 0x03, 0x54, 0x70, 0x78, 0x5e, 0xfb, 0xce, 0x96, 0x7d, 0xad, 0xfd, 0xbc, 0xf4,
	0xe2, 0xb9, 0x82, 0x2f, 0x8a, 0xbf, 0xe8, 0xe3, 0x69, 0xd4, 0xf6, 0x08, 0x5b, 0xa3, 0x2b, 0xc6,
	0x0b, 0x5d, 0x07, 0xe0, 0x04, 0x4a, 0xda, 0xc4, 0x1c, 0xbc, 0x87, 0x26, 0xf0, 0x7f, 0x84, 0xac,
	0x8b, 0xa5, 0x14, 0x39, 0xbe, 0xf8, 0x19, 0xca, 0x36, 0x48, 0xba, 0x1b, 0xe7, 0xbd, 0x09, 0x3b,
	0x2a, 0x53, 0x28, 0xfc, 0xe0, 0x7a, 0x5f, 0xa2, 0x02, 0xd6, 0x27, 0xb2, 0xa3, 0x31, 0x1a, 0xa5,
	0x06, 0xa9, 0xc5, 0xa9, 0x3b, 0x7c, 0xe5, 0x48, 0xb9, 0x85, 0x32, 0x5f, 0xcb, 0xba, 0xaf, 0xc4,
	0x19, 0x07, 0x15, 0xe4, 0x6c, 0x49, 0xb1, 0xa0, 0x0b, 0x00, 0x8d, 0x01, 0x1c, 0x8e, 0x2d, 0xa3,
	0xec, 0x5a, 0x10, 0x84, 0x04, 0x44, 0x87, 0x92, 0xdd, 0x22, 0x6a, 0xc1, 0xd5, 0x11, 0x40, 0x01,
	0xa8, 0xc5, 0x24, 0x5b, 0x32, 0x5f, 0x4b, 0x19, 0x72, 0x66, 0xa5, 0x4c, 0x22, 0x47, 0x24, 0xec,
	0x1e, 0xfd, 0x30, 0xb5, 0x25, 0x8f, 0xd6, 0x0d, 0x94, 0xfc, 0x96, 0x27, 0xdc, 0xea, 0xdf, 0xa6,
	0xec, 0xd8, 0x1e, 0x7a, 0xf0, 0x05, 0x0e, 0x67, 0x26, 0x0e, 0x3e, 0x99, 0x28, 0x06, 0xb4, 0xcc,
	0x3c, 0x82, 0x6e, 0xa0, 0x0b, 0xd2, 0xb5, 0xef, 0x6c, 0x6d, 0xbb, 0x03, 0x25, 0xd5, 0xc6, 0x6b,
	0xc0, 0x67, 0x6b, 0x0c, 0xe5, 0x24, 0xc9, 0xf0, 0x46, 0x52, 0x8d, 0x2e, 0x1d, 0xbb, 0x69, 0xed,
	0x5d, 0xc3, 0xda, 0x4c, 0x9e, 0xa1, 0x12, 0x1b, 0x9d, 0x4f, 0xb7, 0x1e, 0x0e, 0x40, 0xc9, 0x26,
	0x26, 0x15, 0x9a, 0xc5, 0x49, 0xa7, 0xb3, 0x67, 0x5e, 0x2d, 0xd5, 0xed, 0xd7, 0xd2, 0xec, 0xd8,
	0x0f, 0x80, 0x9b, 0x07, 0x18, 0x79, 0x8c, 0xdb, 0x1f, 0xef, 0xf9, 0xf0, 0xbf, 0x5c, 0x8f, 0xfc,
	0xa3, 0x0a, 0x68, 0x1f, 0xcd, 0x61, 0x0e, 0x4d, 0xe8, 0x77, 0x00, 0xa0, 0x20, 0x02, 0x02, 0x24,
	0x90, 0xad, 0x6f, 0x87, 0x36, 0x15, 0x81, 0x8a, 0x33, 0xdc, 0x41, 0xe3, 0x95, 0x21, 0x6d, 0x57,
	0xd4, 0x26, 0xa9, 0xaa, 0xc2, 0x53, 0x0f, 0xbf, 0x5e, 0x42, 0x75, 0x7a, 0x93, 0xae, 0xfc, 0xec,
	0x2a, 0xbb, 0xb6, 0x63, 0x84, 0x03, 0x1f, 0xb9, 0x5b, 0xab, 0x03, 0xa9, 0x47, 0x5f, 0x8a, 0x6a,
	0x68, 0xa1, 0xd3, 0xe2, 0xe2, 0x4c, 0xa1, 0xa8, 0xd0, 0x49, 0x2f, 0x47, 0xa3, 0x13, 0x03, 0xbe,
	0x2b, 0x80, 0x10, 0x12, 0x98, 0x1c, 0x7d, 0xd7, 0x7d, 0x5b, 0x26, 0x14, 0xa5, 0x08, 0xd2, 0xa7,
	0x2b, 0x23, 0x2d, 0xcb, 0x0a, 0x20, 0x4c, 0xe1, 0xb6, 0x60, 0xa4, 0x04, 0x46, 0x72, 0xde, 0xa8,
	0x41, 0xe8, 0x65, 0x0e, 0xd0, 0x04, 0xac, 0xc8, 0xea, 0x0d, 0x37, 0x6c, 0xc0, 0x42, 0xa0, 0xdc,
	0xde, 0x6f, 0x0d, 0x67, 0xf0, 0xa8, 0x08, 0xdc, 0x66, 0xdb, 0x47, 0x87, 0x74, 0xbe, 0x5a, 0xd0,
	0x37, 0xad, 0xd8, 0x38, 0x0d, 0xc1, 0x68, 0x67, 0x13, 0x3d, 0x53, 0x44, 0x70, 0xf9, 0x91, 0x1c,
	0xa3, 0xf4, 0x55, 0x0c, 0xcd, 0xa4, 0x5f, 0x8c, 0x50, 0xc8, 0xfa, 0x8a, 0xdc, 0x2f, 0xc8, 0x6d,
	0xb4, 0x18, 0x87, 0x5c, 0xd4, 0x04, 0x44, 0x66, 0x8d, 0x9c, 0xec, 0x60, 0x32, 0xc9, 0xc1, 0xb5,
	0x1e, 0xc4, 0x46, 0x4a, 0xd5, 0x4a, 0xad, 0x99, 0x47, 0xd2, 0x7f, 0xd6, 0x6f, 0x2a, 0x67, 0x04,
	0xea, 0xd9, 0x49, 0x0c, 0xb4, 0x74, 0x7f, 0xee, 0xc9, 0xc5, 0xd4, 0x3f, 0x01, 0x55, 0x51, 0x2b,
	0x87, 0x66, 0x4f, 0xe4, 0x42, 0xaa, 0x1a, 0xff, 0x80, 0x02, 0x4d, 0xa0, 0xeb, 0x7b, 0xbc, 0x8b,
	0xe7, 0x3c, 0x83, 0x28, 0x59, 0x6c, 0x3b, 0xb0, 0xa6, 0x1e, 0x6c, 0x04, 0xad, 0xc4, 0x9b, 0x46,
	0x5b, 0x24, 0x1d, 0xd5, 0x2b, 0x72, 0x64, 0xdd, 0xd7, 0x0b, 0x3c, 0xc3, 0xe6, 0xaf, 0x46, 0xf3,
	0x87, 0xa4, 0x5a, 0x08, 0x40, 0xb7, 0xc4, 0xbd, 0xa2, 0xef, 0xce, 0xf0, 0x0d, 0xb7, 0x26, 0x19,
	0xb9, 0xe7, 0x94, 0x16, 0x53, 0x57, 0xb5, 0xa1, 0x5c, 0x60, 0xef, 0x51, 0x10, 0x38, 0x0b, 0xdf,
	0x2c, 0xd5, 0xdf, 0x05, 0x28, 0x08, 0x53, 0x88, 0xf8, 0x45, 0xba, 0xc4, 0x89, 0x0b, 0x03, 0xbc,
	0xc5, 0x03, 0x5c, 0xc6, 0xa9, 0x73, 0xfd, 0xd5, 0x68, 0xd2, 0xee, 0x9d, 0xad, 0x4d, 0x18, 0xc0,
	0x2a, 0x47, 0x1b, 0xf2, 0x40, 0xec, 0xb7, 0xb9, 0x97, 0x29, 0x0b, 0x32, 0x3a, 0x86, 0x7f, 0x67,
	0xd2, 0x0b, 0x0d, 0xc6, 0xc3, 0x72, 0xd7, 0xb6, 0x96, 0x98, 0x31, 0xc9, 0x8c, 0xae, 0x9b, 0x76,
	0xa6, 0x59, 0x59, 0x87, 0x1e, 0xcd, 0x47, 0x14, 0x28, 0x58, 0x81, 0xe8, 0x3e, 0x66, 0x7a, 0x6e,
	0x2d, 0xc5, 0x53, 0x6e, 0x1d, 0xdc, 0x31, 0xcb, 0x22, 0xa4, 0x85, 0xc8, 0xce, 0xf4, 0xaa, 0x8a,
	0x41, 0xb1, 0x48, 0x00, 0x6a, 0x0b, 0xa2, 0x2b, 0x3c, 0xb7, 0x45, 0xfe, 0x7b, 0x18, 0x54, 0x93,
	0x66, 0xba, 0x31, 0x38, 0x88, 0xc8, 0x73, 0x99, 0x81, 0xf7, 0xf6, 0x65, 0x87, 0x84, 0x2b, 0x6a,
	0x8d, 0x17, 0x3b, 0x21, 0x99, 0xba, 0x2c, 0x41, 0xc9, 0x1c, 0x9d, 0x22, 0x00, 0x46, 0x5b, 0xab,
	0xa1, 0x7a, 0xe9, 0x5d, 0xa0, 0x94, 0x44, 0x33, 0x36, 0x43, 0x9a, 0xc9, 0x05, 0xc0, 0xe0, 0xae,
	0x66, 0xb6, 0x7a, 0xd9, 0x19, 0x4e, 0xbd, 0xb5, 0xd9, 0x1b, 0xee, 0xdb, 0x86, 0x8a, 0x4b, 0xd5,
	0xa6, 0xdd, 0x74, 0x5b, 0x94, 0x17, 0x55, 0x40, 0x85, 0xda, 0x46, 0x99, 0x26, 0x17, 0xad, 0x1d,
	0x31, 0x66, 0x84, 0x6e, 0x28, 0xa4, 0xf7, 0xf6, 0x91, 0x49, 0x44, 0x83, 0xeb, 0x48, 0x7c, 0x98,
	0x03, 0x2f, 0x48, 0x32, 0x19, 0x0d, 0xb7, 0xe5, 0xd5, 0x98, 0xc7, 0x90, 0x03, 0x10, 0xeb, 0x20,
	0xa3, 0x2c, 0x4c, 0x4d, 0xa9, 0xd5, 0x75, 0x91, 0x4b, 0xca, 0xa9, 0xe1, 0x08, 0x7d, 0x48, 0x69,
	0x4e, 0x8c, 0x8b, 0x7a, 0x20, 0x6e, 0x27, 0xc8, 0x9d, 0xf1, 0xbf, 0x65, 0xca, 0xf5, 0xeb, 0x12,
	0xfc, 0x64, 0x47, 0xfd, 0x66, 0xae, 0x03, 0x6b, 0x39, 0x05, 0x8c, 0x58, 0x0e, 0xf1, 0xf1, 0x71,
	0x96, 0x20, 0x59, 0x69, 0x9c, 0x60, 0xc9, 0x6f, 0x97, 0xd3, 0xde, 0x11, 0x4e, 0xf7, 0x83, 0x69,
	0xb7, 0x3a, 0x9f, 0x37, 0x92, 0x2d, 0x45, 0x07, 0xc0, 0xa1, 0xae, 0xb3, 0x31, 0x04, 0x8d, 0x0b,
	0x82, 0x1b, 0xea, 0x02, 0x8f, 0x06, 0xa0, 0x81, 0x50, 0x50, 0xb2, 0xa0, 0x63, 0x63, 0x00, 0x82,
	0x09, 0x39, 0x5a, 0x47, 0xf5, 0x8b, 0x39, 0xa7, 0x48, 0x6e, 0x83, 0x3e, 0x9d, 0x66, 0x3d, 0x22,
	0x4c, 0xcd, 0xc8, 0x2f, 0xac, 0xf5, 0x04, 0x25, 0x30, 0xd4, 0xd0, 0x90, 0x64, 0x90, 0x84, 0xa8,
	0x4f, 0xea, 0xbf, 0x95, 0x59, 0xf5, 0x1b, 0x9e, 0x9b, 0xb8, 0x0c, 0x66, 0x3d, 0xc2, 0x4a, 0x93,
	0x61, 0xee, 0x05, 0x05, 0x39, 0xe4, 0x40, 0x88, 0xdf, 0x9e, 0x2b, 0xc7, 0x6c, 0x48, 0x60, 0xc7,
	0xfc, 0x5f, 0xb3, 0x65, 0xc6, 0x36, 0x7f, 0x43, 0xbe, 0xa8, 0xf2, 0x0a, 0x13, 0xf0, 0x31, 0x9f,
	0x62, 0x9d, 0x31, 0xd4, 0xa2, 0x26, 0x0f, 0x81, 0x45, 0xcb, 0x10, 0x2d, 0xce, 0x01, 0x87, 0xef,
	0x29, 0x12, 0xdc, 0x6d, 0xbe, 0x9a, 0xb2, 0xcf, 0x69, 0x94, 0x61, 0x0d, 0xe6, 0x57, 0x06, 0xe2,
	0x35, 0x38, 0xa1, 0x71, 0x22, 0x00, 0x1f, 0xc2, 0x0f, 0x51, 0xf0, 0x82, 0x5a, 0xee, 0xde, 0x00,
	0x2d, 0xa8, 0xf5, 0x4a, 0x83, 0x37, 0x2d, 0xae, 0x57, 0xd6, 0x53, 0xca, 0x45, 0xde, 0xd4, 0xd3,
	0xe8, 0xcb, 0xa0, 0x1e, 0xbd, 0xb7, 0xcb, 0xc8, 0xd3, 0x39, 0xe3, 0x67, 0x96, 0x57, 0x57, 0xea,
	0x27, 0xa7, 0xb2, 0xce, 0x32, 0xcb, 0x0c, 0xfa, 0xf3, 0xf2, 0x2a, 0xf2, 0x19, 0x3e, 0xf0, 0x14,
	0x41, 0xcf, 0x7a, 0xd7, 0x50, 0x48, 0xf4, 0x78, 0x92, 0x74, 0x34, 0x8b, 0x3e, 0xcd, 0x72, 0x29,
	0x7d, 0x34, 0x77, 0x94, 0x24, 0x20, 0xf4, 0xb6, 0xe3, 0x5e, 0x86, 0x0f, 0x45, 0x4a, 0x5e, 0xb6,
	0x1c, 0x2f, 0x59, 0x4d, 0x2c, 0x72, 0x0f, 0xa5, 0xdb, 0x70, 0x9e, 0xc4, 0x57, 0x31, 0x77, 0xa5,
	0x69, 0x68, 0x4e, 0x83, 0x53, 0x1e, 0x25, 0x72, 0x92, 0x4d, 0x3e, 0x49, 0xca, 0x31, 0x6b, 0xa7,
	0x20, 0xc4, 0x99, 0x2b, 0xbf, 0x3a, 0x9b, 0x38, 0xa4, 0xba, 0x93, 0x94, 0x46, 0xb7, 0x2d, 0x11,
	0xd0, 0x9d, 0x29, 0xe5, 0x74, 0xc6, 0x2a, 0x7f, 0x98, 0x07, 0x91, 0xd2, 0xa6, 0x4c, 0x94, 0x32,
	0x49, 0x38, 0x15, 0x80, 0xe5, 0x10, 0xb4, 0x57, 0x57, 0xea, 0x33, 0x55, 0xd6, 0xe8, 0xb2, 0xb0,
	0xd5, 0x54, 0x5c, 0x75, 0x4c, 0xbd, 0xc6, 0xd0, 0xd2, 0xc5, 0x86, 0x86, 0xa5, 0xa7, 0xc9, 0x30,
	0x8d, 0x82, 0x63, 0xc4, 0x52, 0xdf, 0xbd, 0x1e, 0x25, 0x8d, 0x57, 0x91, 0x57, 0x94, 0x3b, 0xec,
	0xf8, 0x4b, 0xa2, 0x6e, 0x44, 0x24, 0xf1, 0x77, 0xdf, 0xc3, 0x58, 0xdb, 0x0c, 0x62, 0x4e, 0x32,
	0x5c, 0x20, 0x93, 0x47, 0xdb, 0xa7, 0xd1, 0x02, 0xc9, 0xdf, 0x0e, 0x23, 0x11, 0x45, 0xed, 0x7b,
	0xaa, 0xb7, 0x66, 0xd7, 0x23, 0xb0, 0x43, 0xec, 0x79, 0x4c, 0x90, 0xa8, 0x5f, 0x02, 0x0d, 0xf6,
	0x19, 0x03, 0x23, 0xf7, 0xe3, 0x6f, 0x40, 0xe2, 0x33, 0xf1, 0x4b, 0x42, 0x66, 0x1a, 0x24, 0xaa,
	0x31, 0xcc, 0xdc, 0xbf, 0x63, 0x84, 0xe9, 0x2c, 0x99, 0x99, 0x8d, 0xc5, 0x3c, 0xac, 0x4e, 0xd7,
	0x6c, 0xb2, 0xb1, 0x51, 0xe6, 0x4a, 0x7d, 0x14, 0x56, 0x01, 0xfe, 0x14, 0x3a, 0xb4, 0x78, 0xc9,
	0xa3, 0xbb, 0x96, 0xf2, 0x36, 0x9b, 0x79, 0x5c, 0x0b, 0xed, 0x22, 0x24, 0xef, 0x5d, 0x5f, 0x57,
	0xe3, 0x6e, 0x81, 0xe1, 0x8d, 0x68, 0xe1, 0x7f, 0x7a, 0xeb, 0x85, 0x6b, 0x44, 0xa6, 0x22, 0xb8,
	0x6e, 0x47, 0x59, 0xd3, 0xb9, 0x65, 0xc8, 0x94, 0x22, 0xee, 0x0d, 0x99, 0x2d, 0x92, 0x83, 0xf8,
	0x35, 0xc1, 0x06, 0x80, 0x53, 0x47, 0xde, 0x65, 0x5b, 0x8f, 0xe4, 0x49, 0x71, 0xb6, 0x86, 0x98,
	0x0a, 0x7b, 0xc4, 0xe1, 0x6b, 0xb6, 0x83, 0xe5, 0x08, 0xb0, 0x99, 0xd3, 0x15, 0x91, 0x5e, 0x9e,
	0xa2, 0x66, 0xbe, 0x7d, 0x48, 0x15, 0x17, 0xf7, 0x0f, 0x52, 0x73, 0x11, 0xbf, 0xe8, 0xe6, 0xf3,
	0x2a, 0xef, 0xd4, 0xa0, 0xac, 0x2e, 0xef, 0xb8, 0x22, 0xc9, 0x9d, 0xbc, 0xe2, 0x91, 0xa1, 0xf0,
	0x6d, 0xf5, 0x52, 0x4a, 0xff, 0x5c, 0x30, 0x54, 0xd3, 0x87, 0x8e, 0x98, 0x99, 0x74, 0x92, 0xd4,
	0xb8, 0x9e, 0x44, 0x35, 0x72, 0xc4, 0x59, 0xa4, 0x12, 0x07, 0x54, 0x66, 0x99, 0x86, 0xba, 0x89,
	0x36, 0xaf, 0x84, 0xaa, 0xf1, 0xa3, 0x29, 0xa6, 0x73, 0xf5, 0x48, 0x42, 0xae, 0x61, 0xa4, 0x01,
	0xbf, 0x06, 0x21, 0x78, 0x62, 0xc9, 0x41, 0xe2, 0x34, 0x3a, 0x5c, 0x51, 0xca, 0xfe, 0x3e, 0x63,
	0x47, 0xc3, 0xcc, 0x3d, 0x61, 0x48, 0xe8, 0x77, 0xb0, 0x3a, 0x01, 0x45, 0x9c, 0x79, 0xac, 0x89,
	0x00, 0x4b, 0xfb, 0xe2, 0xb8, 0x68, 0xca, 0xb7, 0x1c, 0x45, 0xaa, 0x29, 0x5a, 0x8a, 0xb0, 0xae,
	0x36, 0x21, 0x38, 0x6d, 0xb6, 0xea, 0x51, 0x60, 0xa2, 0x50, 0x12, 0x71, 0x19, 0x34, 0xe3, 0x77,
	0xc5, 0xa9, 0xc7, 0x88, 0x59, 0x65, 0x0e, 0x8f, 0xdc, 0x3a, 0x7e, 0x31, 0xe3, 0x0c, 0xc5, 0xa4,
	0xc5, 0xe4, 0x33, 0x82, 0x8e, 0xab, 0xb0, 0x0c, 0x02, 0x4f, 0x50, 0xbe, 0x22, 0x8d, 0x0a, 0xb1,
	0x52, 0xbf, 0xc9, 0xb1, 0xa7, 0x9c, 0xe4, 0xe8, 0x89, 0x13, 0xb4, 0x24, 0x60, 0x74, 0xc8, 0xdc,
	0x47, 0x72, 0xa6, 0x5b, 0xc5, 0x05, 0x14, 0x1b, 0x04, 0x89, 0x00, 0x88, 0x9f, 0xf8, 0x29, 0x0b,
	0xca, 0x42, 0x7a, 0x3f, 0x19, 0x6a, 0xaa, 0x73, 0x0d, 0xf8, 0x88, 0x4a, 0x3d, 0x41, 0xf7, 0x4e,
	0xda, 0x21, 0xad, 0x75, 0x98, 0x65, 0x49, 0xca, 0xb8, 0x6f, 0x3c, 0xb5, 0x1a, 0x5d, 0x44, 0xf8,
	0x40, 0x2e, 0x49, 0xf9, 0xef, 0x69, 0xa9, 0x4d, 0xf0, 0xb2, 0xb6, 0xd2, 0xfc, 0xd9, 0x81, 0xc9,
	0x7b, 0x74, 0x22, 0xb3, 0x3a, 0x4d, 0x91, 0x13, 0x7f, 0xb1, 0xf2, 0x3f, 0x2c, 0xd5, 0x27, 0xf3,
	0x68, 0x43, 0xb6, 0x51, 0x79, 0xf6, 0x0f, 0x02, 0xc3, 0xc0, 0x7a, 0xee, 0xc7, 0x0f, 0xc9, 0x7e,
	0xba, 0x13, 0xb6, 0x44, 0xba, 0xf9, 0x99, 0xb8, 0x3f, 0x6b, 0xcd, 0x3e, 0x41, 0x52, 0x28, 0x9e,
	0xfd, 0x13, 0x84, 0xec, 0xc0, 0xd0, 0x09, 0x19, 0x8c, 0xf1, 0xff, 0xa5, 0x7a, 0xa0, 0x6c, 0x84,
	0xb4, 0xb4, 0xf7, 0x08, 0xd2, 0xc9, 0x68, 0x4d, 0x83, 0x59, 0x93, 0xb6, 0xad, 0x28, 0x9a, 0xb0,
	0xb3, 0xde, 0x76, 0x09, 0xc1, 0x53, 0x83, 0x8c, 0x37, 0xa4, 0xa1, 0x40, 0xd7, 0x02, 0x50, 0x09,
	0x6e, 0x48, 0x17, 0x2a, 0x83, 0x21, 0xa2, 0xe6, 0x2d, 0x50, 0x55, 0xe1, 0x78, 0x60, 0x85, 0x11,
	0x61, 0x74, 0x32, 0xca, 0x03, 0xc6, 0x86, 0xd2, 0xf8, 0xb8, 0x80, 0xba, 0x25, 0x4e, 0x9f, 0x10,
	0x16, 0x91, 0xdc, 0x20, 0x1f, 0xa8, 0x54, 0xe9, 0x27, 0x1c, 0xc4, 0xa2, 0x87, 0x03, 0x28, 0x24,
	0xe9, 0x04, 0x46, 0xdf, 0x95, 0xf1, 0x0c, 0x71, 0x79, 0xa9, 0x83, 0x9e, 0x52, 0x91, 0x00, 0xe5,
	0x0d, 0xee, 0x13, 0x9f, 0x1f, 0xe0, 0x2a, 0xd5, 0xaf, 0xc2, 0x9b, 0x34, 0xde, 0x44, 0x11, 0x59,
	0x47, 0x7e, 0xb6, 0x0f, 0x2f, 0x88, 0x9a, 0xa3, 0x02, 0x68, 0x32, 0x1e, 0x56, 0xd1, 0x17, 0x05,
	0x6f, 0x36, 0x0c, 0x2f, 0xbe, 0x88, 0xef, 0x91, 0x22, 0x5b, 0xfd, 0x28, 0xf0, 0x1a, 0xf1, 0x17,
	0x4f, 0x0c, 0x15, 0xab, 0x26, 0x3f, 0x00, 0x15, 0xd9, 0x0f, 0x40, 0xc6, 0x72, 0x69, 0xb1, 0x3e,
	0x94, 0xe5, 0x12, 0xff, 0xbc, 0x03, 0x79, 0xd9, 0x68, 0xcc, 0x54, 0x28, 0xc6, 0x93, 0x71, 0x41,
	0x7f, 0x2e, 0xaf, 0x92, 0xe3, 0xd4, 0xd4, 0x71, 0x45, 0xee, 0xb8, 0x71, 0x0f, 0xc5, 0x1e, 0xa4,
	0x01, 0x75, 0xea, 0xfd, 0x5f, 0xf1, 0x53, 0xcf, 0xb0, 0x77, 0xdb, 0x3a, 0xda, 0x37, 0x91, 0xe6,
	0x67, 0x7f, 0x3c, 0x3b, 0x23, 0x44, 0xc9, 0xf6, 0xea, 0xd9, 0x16, 0xc6, 0xad, 0xe6, 0xb1, 0x91,
	0x4f, 0x67, 0x07, 0x12, 0xf4, 0x2b, 0xf4, 0xd4, 0x94, 0xc0, 0x25, 0x1a, 0x46, 0x01, 0x98, 0xe0,
	0x68, 0xac, 0x7b, 0x5a, 0xa7, 0x0c, 0x15, 0xf7, 0xfc, 0x1f, 0xfd, 0x40, 0x73, 0xeb, 0x9a, 0x93,
	0xe3, 0xb0, 0x88, 0x01, 0xa5, 0x37, 0xbe, 0x0f, 0x62, 0x4c, 0xa9, 0xd0, 0x78, 0x3b, 0xfe, 0xf9,
	0x8e, 0x83, 0x5a, 0xd2, 0x3a, 0x59, 0xd3, 0x70, 0x15, 0x43, 0x3c, 0x16, 0x45, 0x41, 0xa3, 0x84,
	0x66, 0x7c, 0xd4, 0x7d, 0xb7, 0x75, 0xde, 0xfe, 0x57, 0x50, 0x82, 0x3a, 0x2d, 0x59, 0x46, 0xbf,
	0x7d, 0x8a, 0x87, 0xf9, 0x9d, 0x74, 0x33, 0x0e, 0x79, 0xc5, 0xf8, 0x73, 0xcd, 0xff, 0x00, 0x30,
	0x4a, 0x56, 0xa4 };

#if defined( __GNUC__ ) && !defined( LIBPFF_DLL_IMPORT )

/* Tests the libpff_deflate_decompress function
 * Returns 1 if successful or 0 if not
 */
int pff_test_deflate_decompress(
     void )
{
	uint8_t uncompressed_data[ 8192 ];

	libcerror_error_t *error      = NULL;
	size_t uncompressed_data_size = 7640;
	int result                    = 0;

	result = libpff_deflate_decompress(
	          pff_test_deflate_compressed_byte_stream,
	          2627,
	          uncompressed_data,
	          &uncompressed_data_size,
	          &error );

	PFF_TEST_FPRINT_ERROR( error )

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	PFF_TEST_ASSERT_EQUAL_SIZE(
	 "uncompressed_data_size",
	 uncompressed_data_size,
	 (size_t) 7640 );

	/* Test error cases
	 */
	result = libpff_deflate_decompress(
	          NULL,
	          2627,
	          uncompressed_data,
	          &uncompressed_data_size,
	          &error );

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        PFF_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libpff_deflate_decompress(
	          pff_test_deflate_compressed_byte_stream,
	          (size_t) SSIZE_MAX + 1,
	          uncompressed_data,
	          &uncompressed_data_size,
	          &error );

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        PFF_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libpff_deflate_decompress(
	          pff_test_deflate_compressed_byte_stream,
	          2627,
	          NULL,
	          &uncompressed_data_size,
	          &error );

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        PFF_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libpff_deflate_decompress(
	          pff_test_deflate_compressed_byte_stream,
	          2627,
	          uncompressed_data,
	          NULL,
	          &error );

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        PFF_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBPFF_DLL_IMPORT ) */

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc PFF_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] PFF_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc PFF_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] PFF_TEST_ATTRIBUTE_UNUSED )
#endif
{
	PFF_TEST_UNREFERENCED_PARAMETER( argc )
	PFF_TEST_UNREFERENCED_PARAMETER( argv )

#define PFF_TEST_DEFLATE
#if defined( HAVE_DEBUG_OUTPUT ) && defined( PFF_TEST_DEFLATE )
	libcnotify_verbose_set(
	 1 );
	libcnotify_stream_set(
	 stderr,
	 NULL );
#endif

#if defined( __GNUC__ ) && !defined( LIBPFF_DLL_IMPORT )

	/* TODO add tests for libpff_deflate_bit_stream_get_value */

	/* TODO add tests for libpff_deflate_huffman_table_construct */

	/* TODO add tests for libpff_deflate_bit_stream_get_huffman_encoded_value */

	/* TODO add tests for libpff_deflate_bit_stream_get_huffman_encoded_codes_array */

	/* TODO add tests for libpff_deflate_calculate_adler32 */

	PFF_TEST_RUN(
	 "libpff_deflate_decompress",
	 pff_test_deflate_decompress );

#endif /* defined( __GNUC__ ) && !defined( LIBPFF_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}


/* Author: BrainInAVat7
 * COPYRIGHT: (c) 2026 BrainInAVat7
 * LICENSE: AGPL-3.0
 *
 * This timing helper provides a thin abstraction over
 * POSIX and Windows functions to get a precision
 * timing count and precision timing frequency.
 *
 * This file implements the public header.
 *
 * For more information see attached README.md
 * See LICENSE for licensing information.
 */


#ifndef VAT7_TIMING_H
#define VAT7_TIMING_H


#include <stdint.h>


/* Get a precision timing count at sub-microsecond resolution.
 * These timing counts are only meaningful when compared relatively
 * to one another and are guaranteed to be monotonic.
 */
uint64_t vat7_timing_count (void);

/* Get a precision timing frequency in count per second.
 */
uint64_t vat7_timing_frequency (void);


#endif  /* Header guard */

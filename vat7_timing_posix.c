/* Author: BrainInAVat7
 * COPYRIGHT: (c) 2026 BrainInAVat7
 * LICENSE: AGPL-3.0
 *
 * Vat7 Timing
 *
 * This timing helper provides a thin abstraction over
 * POSIX and Windows functions to get a precision
 * timing count and precision timing frequency.
 *
 * This file implements the POSIX version.
 *
 * For more information see attached README.md
 * See LICENSE for licensing information.
 */

#define _POSIX_C_SOURCE 199309L

#include "vat7_timing.h"

#include <stdint.h>
#include <time.h>

#include <unistd.h>


#define VAT7_NANOSECONDS_PER_SECOND (uint64_t)1000000000


/* Get a precision timing count at sub-microsecond resolution.
 * These timing counts are only meaningful when compared relatively
 * to one another and are guaranteed to be monotonic.
 */
uint64_t vat7_timing_count (void)
{
	struct timespec ts;
	/* This returns 0 on success, -1 on failure but realistically,
	 * it should never fail. The WINDOWS versions do not return error
	 * values, so ignoring it here for parity
	 */
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (uint64_t)ts.tv_sec * VAT7_NANOSECONDS_PER_SECOND
		+ (uint64_t)ts.tv_nsec;
}


/* Get a precision timing frequency in count per second.
 */
uint64_t vat7_timing_frequency (void)
{
	/* This works because the POSIX standard ensures that the
	 * counter value is in nanoseconds */
	return VAT7_NANOSECONDS_PER_SECOND;
}


/* Pause execution for a given number of milliseconds.
 */
void vat7_timing_wait (double milliseconds)
{
	uint64_t wait_start = vat7_timing_count();
	uint32_t ms;
	struct timespec wait_timespec;
	wait_timespec.tv_nsec = 1000000;
	wait_timespec.tv_sec = 0;

	// TODO move the magic number 3 here to a #define
	for (ms = (uint32_t)milliseconds; ms > 3; ms--)
	{
		nanosleep(&wait_timespec, NULL);
	}
	while ((double)(vat7_timing_count() - wait_start)
		/ (double)vat7_timing_frequency()
		< milliseconds * 0.001 // to convert seconds
	)
	{ /* Do nothing */ }
}


#undef VAT7_NANOSECONDS_PER_SECOND
#undef _POSIX_C_SOURCE

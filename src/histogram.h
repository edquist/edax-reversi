/**
 * @file histogram.h
 *
 * Histogram management.
 *
 * @date 1998 - 2017
 * @author Richard Delorme
 * @version 4.4
 */

#ifndef EDAX_HISTOGRAM_H
#define EDAX_HISTOGRAM_H

/* declaration */
void histogram_init(u64 h[129][65]);
void histogram_print(u64 h[129][65]);
void histogram_stats(u64 h[129][65]);
void histogram_to_ppm(const char *file, u64 histogram[129][65]);

#endif


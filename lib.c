#include <stdint.h>
#include "hdr/hdr_histogram.h"

int64_t hdr_test(int *dummy, int *dummy2)
{
	struct hdr_histogram *hdr;

	int res = hdr_init(1, 60000, 2, &hdr);
	hdr->counts[100] = 5;
	hdr->counts[121] = 1;

	hdr_reset_internal_counters(hdr);

	return hdr->total_count;
}

/****************************************************************************
 * RRDtool 1.4.8  Copyright by Tobi Oetiker, 1997-2013
 ****************************************************************************
 * rrd_create.h
 ****************************************************************************/
#ifdef  __cplusplus
extern    "C" {
#endif

#ifndef _RRD_CREATE_H
#define _RRD_CREATE_H

#include "rrd.h"

int parseDS(const char *def, 
	    ds_def_t *ds_def,
	    void *key_hash,
	    long (*lookup)(void *, char *));

/* Parse a textual RRA definition into rra_def. The rra_def might be
   disconnected from any RRD. However, because some definitions cause
   modifications to other parts of an RRD (like the version) it is
   possible to pass the RRD that is about to hold the RRA. If the
   definition really is to stay disconnected, it is permitted to pass
   NULL to the rrd parameter.
   The hash is a parameter to introduce some randomness to avoid 
   potential performance problems when doing bulk updates to many RRDs
   at once.
*/
int parseRRA(const char *def,
	     rra_def_t *rra_def, 
	     rrd_t *rrd,
	     unsigned long hash);

rra_def_t *handle_dependent_rras(rra_def_t *rra_def_array, 
				 long unsigned int *rra_cnt, 
				 unsigned long hash);

void init_cdp(const rrd_t *rrd, 
	      const rra_def_t *rra_def, 
	      cdp_prep_t *cdp_prep);

#endif


#ifdef  __cplusplus
}
#endif

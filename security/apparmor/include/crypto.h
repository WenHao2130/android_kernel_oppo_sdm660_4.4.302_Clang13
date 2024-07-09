/*
 * AppArmor security module
 *
 * This file contains AppArmor policy loading interface function definitions.
 *
 * Copyright 2013 Canonical Ltd.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, version 2 of the
 * License.
 */

#ifndef __APPARMOR_CRYPTO_H
#define __APPARMOR_CRYPTO_H

#include "policy.h"

static inline int aa_calc_profile_hash(struct aa_profile *profile, u32 version,
				       void *start, size_t len)
{
	return 0;
}

static inline unsigned int aa_hash_size(void)
{
	return 0;
}

#endif /* __APPARMOR_CRYPTO_H */

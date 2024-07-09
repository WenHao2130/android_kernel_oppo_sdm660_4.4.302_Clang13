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
 *
 * Fns to provide a checksum of policy that has been loaded this can be
 * compared to userspace policy compiles to check loaded policy is what
 * it should be.
 */

#include <crypto/hash.h>

#include "include/apparmor.h"
#include "include/crypto.h"

static unsigned int apparmor_hash_size;

static int __init init_profile_hash(void)
{
	struct crypto_shash *tfm;

	if (!apparmor_initialized)
		return 0;

	tfm = crypto_alloc_shash("sha1", 0, CRYPTO_ALG_ASYNC);
	if (IS_ERR(tfm)) {
		int error = PTR_ERR(tfm);
		AA_ERROR("failed to setup profile sha1 hashing: %d\n", error);
		return error;
	}
	aa_info_message("AppArmor sha1 policy hashing enabled");

	return 0;
}

late_initcall(init_profile_hash);

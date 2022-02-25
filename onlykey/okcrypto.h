/* Tim Steiner
 * Copyright (c) 2015-2018, CryptoTrust LLC.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by CryptoTrust LLC. for
 *    the OnlyKey Project (http://www.crp.to/ok)"
 *
 * 4. The names "OnlyKey" and "OnlyKey Project" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    admin@crp.to.
 *
 * 5. Products derived from this software may not be called "OnlyKey"
 *    nor may "OnlyKey" or "CryptoTrust" appear in their names without
 *    specific prior written permission. For written permission, please
 *    contact admin@crp.to.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by CryptoTrust LLC. for
 *    the OnlyKey Project (http://www.crp.to/ok)"
 *
 * 7. Redistributions in any form must be accompanied by information on
 *    how to obtain complete source code for this software and any
 *    accompanying software that uses this software. The source code
 *    must either be included in the distribution or be available for
 *    no more than the cost of distribution plus a nominal fee, and must
 *    be freely redistributable under reasonable conditions. For a
 *    binary file, complete source code means the source code for all
 *    modules it contains.
 *
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE
 * GRANTED BY THIS LICENSE. IF SOFTWARE RECIPIENT INSTITUTES PATENT LITIGATION
 * AGAINST ANY ENTITY (INCLUDING A CROSS-CLAIM OR COUNTERCLAIM IN A LAWSUIT)
 * ALLEGING THAT THIS SOFTWARE (INCLUDING COMBINATIONS OF THE SOFTWARE WITH
 * OTHER SOFTWARE OR HARDWARE) INFRINGES SUCH SOFTWARE RECIPIENT'S PATENT(S),
 * THEN SUCH SOFTWARE RECIPIENT'S RIGHTS GRANTED BY THIS LICENSE SHALL TERMINATE
 * AS OF THE DATE SUCH LITIGATION IS FILED. IF ANY PROVISION OF THIS AGREEMENT
 * IS INVALID OR UNENFORCEABLE UNDER APPLICABLE LAW, IT SHALL NOT AFFECT
 * THE VALIDITY OR ENFORCEABILITY OF THE REMAINDER OF THE TERMS OF THIS
 * AGREEMENT, AND WITHOUT FURTHER ACTION BY THE PARTIES HERETO, SUCH
 * PROVISION SHALL BE REFORMED TO THE MINIMUM EXTENT NECESSARY TO MAKE
 * SUCH PROVISION VALID AND ENFORCEABLE. ALL SOFTWARE RECIPIENT'S RIGHTS UNDER
 * THIS AGREEMENT SHALL TERMINATE IF IT FAILS TO COMPLY WITH ANY OF THE MATERIAL
 * TERMS OR CONDITIONS OF THIS AGREEMENT AND DOES NOT CURE SUCH FAILURE IN
 * A REASONABLE PERIOD OF TIME AFTER BECOMING AWARE OF SUCH NONCOMPLIANCE.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifdef STD_VERSION


#ifndef OKCRYPTO_H
#define OKCRYPTO_H

#include <Ed25519.h>
#include <Curve25519.h>
#include <SHA256_2.h>
#include "rsa.h"
#include "tweetnacl.h"


#ifdef __cplusplus
extern "C"
{
#endif


extern void okcrypto_sign (uint8_t *buffer);
extern void okcrypto_decrypt (uint8_t *buffer);
extern void okcrypto_hmacsha1 ();
extern void okcrypto_derive_key (uint8_t type, uint8_t *data, uint8_t slot);
extern int okcrypto_shared_secret (uint8_t *pub, uint8_t *secret);
extern void okcrypto_aes_crypto_box (uint8_t *buffer, int len, bool open);
extern void okcrypto_getpubkey (uint8_t *buffer);
extern void okcrypto_generate_random_key (uint8_t *buffer);
extern void okcrypto_geteccpubkey (uint8_t *buffer);
extern void okcrypto_getrsapubkey (uint8_t *buffer);
extern void okcrypto_ecdh (uint8_t *buffer);
extern void okcrypto_rsadecrypt(uint8_t *buffer);
extern void okcrypto_rsasign (uint8_t *buffer);
extern void okcrypto_ecdsa_eddsa (uint8_t *buffer);
extern void okcrypto_hkdf(const void *data, const void *inputKey, void *outputKey, const size_t L);
extern void okcrypto_split_sundae(uint8_t *state, uint8_t *iv, int len, uint8_t function, bool s);
extern void okcrypto_compute_pubkey();
extern void swap_buffer (uint8_t start, uint8_t end, uint8_t * buffer);

extern uint8_t Challenge_button1;
extern uint8_t Challenge_button2;
extern uint8_t Challenge_button3;
extern uint8_t CRYPTO_AUTH;

extern int rsa_decrypt (unsigned int *olen, const uint8_t *in, uint8_t *out);
extern int rsa_sign (int mlen, const uint8_t *msg, uint8_t *out);
extern void rsa_getpub (uint8_t type);
extern bool is_bit_set(unsigned char byte, int index);
extern int mbedtls_rand( void *rng_state, unsigned char *output, size_t len);
extern int rsa_encrypt (int len, const uint8_t *in, uint8_t *out);

extern void crypto_sha512_init();
extern void crypto_sha512_update(const uint8_t * data, size_t len);
extern void crypto_sha512_final(uint8_t * hash);

extern void okcrypto_aes_gcm_encrypt (uint8_t * state, uint8_t slot, uint8_t value, const uint8_t * key, int len);
extern void okcrypto_aes_gcm_decrypt (uint8_t * state, uint8_t slot, uint8_t value, const uint8_t * key, int len);
extern void okcrypto_aes_gcm_encrypt2 (uint8_t * state, uint8_t * iv1, const uint8_t * key, int len, bool s);
extern void okcrypto_aes_gcm_decrypt2 (uint8_t * state, uint8_t * iv1, const uint8_t * key, int len, bool s);
extern void okcrypto_aes_cbc_encrypt (uint8_t * state, uint8_t * iv, const uint8_t * key, int len);
extern void okcrypto_aes_cbc_decrypt (uint8_t * state, uint8_t * iv, const uint8_t * key, int len);


#ifdef __cplusplus
}
#endif
#endif
#endif

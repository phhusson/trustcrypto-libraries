/* 
 * Copyright (c) 2015-2020, CryptoTrust LLC.
 * All rights reserved.
 * 
 * Author : Tim Steiner <t@crp.to>
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
 *    the OnlyKey Project (https://crp.to/ok)"
 *
 * 4. The names "OnlyKey" and "CryptoTrust" must not be used to
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
 *    the OnlyKey Project (https://crp.to/ok)"
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
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS
 * ARE GRANTED BY THIS LICENSE. IF SOFTWARE RECIPIENT INSTITUTES PATENT
 * LITIGATION AGAINST ANY ENTITY (INCLUDING A CROSS-CLAIM OR COUNTERCLAIM
 * IN A LAWSUIT) ALLEGING THAT THIS SOFTWARE (INCLUDING COMBINATIONS OF THE
 * SOFTWARE WITH OTHER SOFTWARE OR HARDWARE) INFRINGES SUCH SOFTWARE
 * RECIPIENT'S PATENT(S), THEN SUCH SOFTWARE RECIPIENT'S RIGHTS GRANTED BY
 * THIS LICENSE SHALL TERMINATE AS OF THE DATE SUCH LITIGATION IS FILED. IF
 * ANY PROVISION OF THIS AGREEMENT IS INVALID OR UNENFORCEABLE UNDER
 * APPLICABLE LAW, IT SHALL NOT AFFECT THE VALIDITY OR ENFORCEABILITY OF THE
 * REMAINDER OF THE TERMS OF THIS AGREEMENT, AND WITHOUT FURTHER ACTION
 * BY THE PARTIES HERETO, SUCH PROVISION SHALL BE REFORMED TO THE MINIMUM
 * EXTENT NECESSARY TO MAKE SUCH PROVISION VALID AND ENFORCEABLE. ALL
 * SOFTWARE RECIPIENT'S RIGHTS UNDER THIS AGREEMENT SHALL TERMINATE IF IT
 * FAILS TO COMPLY WITH ANY OF THE MATERIAL TERMS OR CONDITIONS OF THIS
 * AGREEMENT AND DOES NOT CURE SUCH FAILURE IN A REASONABLE PERIOD OF
 * TIME AFTER BECOMING AWARE OF SUCH NONCOMPLIANCE. THIS SOFTWARE IS
 * PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */



//#include <Arduino.h>
#include <avr/eeprom.h>
#include "okeeprom.h"


/*********************************/
/*********************************/
void okeeprom_eeget_common(
	uint8_t	*ptr,
	int	addr,
	int	len)
{
    while (len--) {
	*ptr++ = eeprom_read_byte(addr++);
    }
}

void okeeprom_eeset_common(
	uint8_t	*ptr,
	int	addr,
	int	len)
{
    while (len--) {
	eeprom_write_byte(addr++, *ptr++);
    }
}
/*********************************/
/*********************************/
int okeeprom_eeget_backupkey (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_backupkey, EElen_backupkey);
    return EElen_backupkey;
}
void okeeprom_eeset_backupkey (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_backupkey, EElen_backupkey);
}
/*********************************/
/*********************************/
int okeeprom_eeget_timeout (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_timeout, EElen_timeout);
    return EElen_timeout;
}
void okeeprom_eeset_timeout (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_timeout, EElen_timeout);
}
/*********************************/
/*********************************/
int okeeprom_eeget_wipemode (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_wipemode, EElen_wipemode);
    return EElen_wipemode;
}
void okeeprom_eeset_wipemode (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_wipemode, EElen_wipemode);
}
/*********************************/
/*********************************/
int okeeprom_eeget_ctap_authstate (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_ctap_authstate, EElen_ctap_authstate);
    return EElen_ctap_authstate;
}
void okeeprom_eeset_ctap_authstate (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_ctap_authstate, EElen_ctap_authstate);
}

/*********************************/
/*********************************/
int okeeprom_eeget_backupkeymode (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_backupkeymode, EElen_backupkeymode);
    return EElen_backupkeymode;
}
void okeeprom_eeset_backupkeymode (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_backupkeymode, EElen_backupkeymode);
}
/*********************************/
/*********************************/
int okeeprom_eeget_derived_key_challenge_mode (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_derived_key_challenge_mode, EElen_derived_key_challenge_mode);
    return EElen_derived_key_challenge_mode;
}
void okeeprom_eeset_derived_key_challenge_mode (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_derived_key_challenge_mode, EElen_derived_key_challenge_mode);
}
/*********************************/
/*********************************/
int okeeprom_eeget_stored_key_challenge_mode (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_stored_key_challenge_mode, EElen_stored_key_challenge_mode);
    return EElen_stored_key_challenge_mode;
}
void okeeprom_eeset_stored_key_challenge_mode (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_stored_key_challenge_mode, EElen_stored_key_challenge_mode);
}
/*********************************/
/*********************************/
int okeeprom_eeget_hmac_challengemode (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_hmac_challengemode, EElen_hmac_challengemode);
    return EElen_hmac_challengemode;
}
void okeeprom_eeset_hmac_challengemode (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_hmac_challengemode, EElen_hmac_challengemode);
}
/*********************************/
/*********************************/
int okeeprom_eeget_modkey (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_modkey, EElen_modkey);
    return EElen_modkey;
}
void okeeprom_eeset_modkey (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_modkey, EElen_modkey);
}
/*********************************/
/*********************************/
int okeeprom_eeget_2ndprofilemode (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_2ndprofilemode, EElen_2ndprofilemode);
    return EElen_2ndprofilemode;
}
void okeeprom_eeset_2ndprofilemode (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_2ndprofilemode, EElen_2ndprofilemode);
}
/*********************************/
/*********************************/
int okeeprom_eeget_typespeed (uint8_t *ptr, int slot) {
	if (slot == 0) {
    	okeeprom_eeget_common(ptr, EEpos_typespeed, EElen_typespeed);
	} else if (slot > 0 && slot < 13) {
		okeeprom_eeget_common(ptr, EEpos_slottypespeed+slot-1, EElen_typespeed);
		*ptr &= 0x0F;
	} else if (slot > 12 && slot < 25) {
		okeeprom_eeget_common(ptr, EEpos_slottypespeed+slot-1, EElen_typespeed);
		*ptr &= 0xF0;
		*ptr = (*ptr>>4);
	}
    return EElen_typespeed;
}
void okeeprom_eeset_typespeed (uint8_t *ptr, int slot) {
	uint8_t temp;
	okeeprom_eeget_common(temp, EEpos_slottypespeed+slot-1, EElen_typespeed);
	if (slot == 0) {
		okeeprom_eeset_common(ptr, EEpos_typespeed, EElen_typespeed);
	} else if (slot > 0 && slot < 13) {
		temp &= 0xF0;
		temp += *ptr;
		okeeprom_eeset_common((uint8_t *)temp, EEpos_slottypespeed+slot-1, EElen_typespeed);
	} else if (slot > 12 && slot < 25) {
		temp &= 0x0F;
		temp += (*ptr<<4);
		okeeprom_eeset_common((uint8_t *)temp, EEpos_slottypespeed+slot-1, EElen_typespeed);
	}
}
/*********************************/
/*********************************/
int okeeprom_eeget_keyboardlayout (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_keyboardlayout, EElen_keyboardlayout);
    return EElen_keyboardlayout;
}
void okeeprom_eeset_keyboardlayout (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_keyboardlayout, EElen_keyboardlayout);
}
/*********************************/
/*********************************/
int okeeprom_eeget_ledbrightness (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_ledbrightness, EElen_ledbrightness);
    return EElen_ledbrightness;
}
void okeeprom_eeset_ledbrightness (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_ledbrightness, EElen_ledbrightness);
}
/*********************************/
/*********************************/
int okeeprom_eeget_touchoffset (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_touchoffset, EElen_touchoffset);
    return EElen_ledbrightness;
}
void okeeprom_eeset_touchoffset (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_touchoffset, EElen_touchoffset);
}
/*********************************/
/*********************************/
int okeeprom_eeget_autolockslot (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_autolockslot, EElen_autolockslot);
    return EElen_autolockslot;
}
void okeeprom_eeset_autolockslot (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_autolockslot, EElen_autolockslot);
}
/*********************************/
/*********************************/
int okeeprom_eeget_sincelastregularlogin (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_sincelastregularlogin, EElen_sincelastregularlogin);
    return EElen_sincelastregularlogin;
}
void okeeprom_eeset_sincelastregularlogin (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_sincelastregularlogin, EElen_sincelastregularlogin);
}

/*********************************/
/*********************************/
int okeeprom_eeget_failedlogins (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_failedlogins, EElen_failedlogins);
    return EElen_failedlogins;
}
void okeeprom_eeset_failedlogins (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_failedlogins, EElen_failedlogins);
}
/*********************************/
/*********************************/
int okeeprom_eeget_nonce2 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_nonce2, EElen_nonce2);
    return EElen_nonce2;
}
void okeeprom_eeset_nonce2 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_nonce2, EElen_nonce2);
}
/*********************************/
/*********************************/
int okeeprom_eeget_U2Fcertlen (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_U2Fcertlen, EElen_U2Fcertlen);
    return EElen_U2Fcertlen;
}
void okeeprom_eeset_U2Fcertlen (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_U2Fcertlen, EElen_U2Fcertlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_flashpos (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_flashpos, EElen_flashpos);
    return EElen_flashpos;
}
void okeeprom_eeset_flashpos (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_flashpos, EElen_flashpos);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen1 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password1len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen1 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password1len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen2 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password2len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen2 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password2len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen3 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password3len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen3 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password3len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen4 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password4len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen4 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password4len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen5 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password5len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen5 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password5len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen6 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password6len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen6 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password6len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen7 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password7len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen7 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password7len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen8 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password8len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen8 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password8len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen9 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password9len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen9 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password9len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen10 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password10len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen10 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password10len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen11 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password11len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen11 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password11len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen12 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password12len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen12 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password12len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen13 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password13len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen13 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password13len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen14 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password14len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen14 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password14len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen15 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password15len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen15 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password15len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen16 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password16len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen16 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password16len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen17 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password17len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen17 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password17len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen18 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password18len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen18 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password18len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen19 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password19len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen19 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password19len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen20 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password20len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen20 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password20len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen21 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password21len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen21 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password21len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen22 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password22len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen22 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password22len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen23 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password23len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen23 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password23len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_passwordlen24 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_password24len, EElen_passwordlen);
    return EElen_passwordlen;
}
void okeeprom_eeset_passwordlen24 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_password24len, EElen_passwordlen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen1 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username1len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen1 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username1len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen2 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username2len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen2 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username2len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen3 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username3len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen3 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username3len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen4 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username4len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen4 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username4len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen5 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username5len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen5 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username5len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen6 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username6len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen6 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username6len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen7 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username7len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen7 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username7len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen8 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username8len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen8 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username8len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen9 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username9len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen9 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username9len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen10 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username10len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen10 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username10len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen11 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username11len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen11 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username11len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen12 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username12len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen12 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username12len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen13 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username13len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen13 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username13len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen14 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username14len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen14 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username14len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen15 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username15len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen15 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username15len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen16 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username16len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen16 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username16len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen17 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username17len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen17 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username17len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen18 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username18len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen18 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username18len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen19 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username19len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen19 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username19len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen20 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username20len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen20 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username20len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen21 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username21len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen21 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username21len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen22 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username22len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen22 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username22len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen23 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username23len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen23 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username23len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_usernamelen24 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_username24len, EElen_usernamelen);
    return EElen_usernamelen;
}
void okeeprom_eeset_usernamelen24 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_username24len, EElen_usernamelen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen1 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url1len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen1 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url1len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen2 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url2len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen2 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url2len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen3 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url3len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen3 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url3len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen4 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url4len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen4 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url4len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen5 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url5len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen5 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url5len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen6 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url6len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen6 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url6len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen7 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url7len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen7 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url7len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen8 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url8len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen8 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url8len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen9 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url9len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen9 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url9len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen10 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url10len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen10 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url10len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen11 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url11len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen11 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url11len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen12 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url12len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen12 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url12len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen13 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url13len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen13 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url13len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen14 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url14len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen14 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url14len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen15 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url15len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen15 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url15len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen16 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url16len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen16 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url16len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen17 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url17len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen17 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url17len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen18 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url18len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen18 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url18len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen19 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url19len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen19 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url19len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen20 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url20len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen20 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url20len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen21 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url21len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen21 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url21len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen22 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url22len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen22 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url22len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen23 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url23len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen23 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url23len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_urllen24 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_url24len, EElen_urllen);
    return EElen_urllen;
}
void okeeprom_eeset_urllen24 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_url24len, EElen_urllen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen1 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey1len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen1 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey1len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen2 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey2len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen2 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey2len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen3 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey3len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen3 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey3len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen4 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey4len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen4 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey4len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen5 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey5len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen5 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey5len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen6 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey6len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen6 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey6len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen7 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey7len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen7 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey7len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen8 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey8len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen8 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey8len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen9 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey9len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen9 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey9len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen10 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey10len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen10 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey10len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen11 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey11len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen11 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey11len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen12 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey12len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen12 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey12len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen13 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey13len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen13 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey13len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen14 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey14len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen14 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey14len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen15 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey15len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen15 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey15len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen16 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey16len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen16 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey16len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen17 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey17len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen17 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey17len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen18 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey18len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen18 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey18len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen19 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey19len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen19 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey19len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen20 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey20len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen20 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey20len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen21 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey21len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen21 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey21len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen22 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey22len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen22 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey22len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen23 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey23len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen23 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey23len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_totpkeylen24 (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_totpkey24len, EElen_totpkeylen);
    return EElen_totpkeylen;
}
void okeeprom_eeset_totpkeylen24 (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_totpkey24len, EElen_totpkeylen);
}
/*********************************/
/*********************************/
int okeeprom_eeget_aeskey_DEPRICATED (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_aeskey, EElen_aeskey);
    return EElen_aeskey;
}
void okeeprom_eeset_aeskey_DEPRICATED (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_aeskey, EElen_aeskey);
}
/*********************************/
/*********************************/
int yubikey_eeget_counter (uint8_t *ptr, uint8_t slot) {
	if (slot == 0) {
		okeeprom_eeget_common(ptr, EEpos_counter_DEPRICATED, EElen_counter);
	} else if (slot > 0 && slot < 25) {
		okeeprom_eeget_common(ptr, EEpos_totpkey1len+slot-1, 1);
		okeeprom_eeget_common(ptr+1, EEpos_yubicounterpart+slot-1, 1);
	}
    return EElen_counter;
}
void yubikey_eeset_counter (uint8_t *ptr, uint8_t slot) {
    if (slot == 0) {
		okeeprom_eeset_common(ptr, EEpos_counter_DEPRICATED, EElen_counter);
	} else if (slot > 0 && slot < 25) {
		okeeprom_eeset_common(ptr, EEpos_totpkey1len+slot-1, 1);
		okeeprom_eeset_common(ptr+1, EEpos_yubicounterpart+slot-1, 1);
	}
}
/*********************************/
/*********************************/
int okeeprom_eeget_private_DEPRICATED (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_private, EElen_private);
    return EElen_private;
}
void okeeprom_eeset_private_DEPRICATED (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_private, EElen_private);
}
/*********************************/
/*********************************/
int okeeprom_eeget_public_DEPRICATED (uint8_t *ptr) {
    okeeprom_eeget_common(ptr, EEpos_public, EElen_public);
    return EElen_public;
}
void okeeprom_eeset_public_DEPRICATED (uint8_t *ptr) {
    okeeprom_eeset_common(ptr, EEpos_public, EElen_public);
}
/*********************************/
/*********************************/
int okeeprom_eeget_password (uint8_t *ptr, int slot) {

	switch (slot) {
		uint8_t length;
		int size;
        	case 1:
			okeeprom_eeget_passwordlen1(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password1, EElen_password);
			return size;
            break;
		case 2:
			okeeprom_eeget_passwordlen2(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password2, EElen_password);
			return size;
            break;
		case 3:
			okeeprom_eeget_passwordlen3(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password3, EElen_password);
			return size;
            break;
		case 4:
			okeeprom_eeget_passwordlen4(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password4, EElen_password);
			return size;
            break;
		case 5:
			okeeprom_eeget_passwordlen5(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password5, EElen_password);
			return size;
            break;
		case 6:
			okeeprom_eeget_passwordlen6(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password6, EElen_password);
			return size;
            break;
		case 7:
			okeeprom_eeget_passwordlen7(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password7, EElen_password);
			return size;
            break;
		case 8:
			okeeprom_eeget_passwordlen8(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password8, EElen_password);
			return size;
            break;
		case 9:
			okeeprom_eeget_passwordlen9(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password9, EElen_password);
			return size;
            break;
		case 10:
			okeeprom_eeget_passwordlen10(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password10, EElen_password);
			return size;
            break;
		case 11:
			okeeprom_eeget_passwordlen11(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password11, EElen_password);
			return size;
            break;
		case 12:
			okeeprom_eeget_passwordlen12(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password12, EElen_password);
			return size;
            break;
		case 13:
			okeeprom_eeget_passwordlen13(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password13, EElen_password);
			return size;
            break;
		case 14:
			okeeprom_eeget_passwordlen14(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password14, EElen_password);
			return size;
            break;
		case 15:
			okeeprom_eeget_passwordlen15(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password15, EElen_password);
			return size;
            break;
		case 16:
			okeeprom_eeget_passwordlen16(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password16, EElen_password);
			return size;
            break;
		case 17:
			okeeprom_eeget_passwordlen17(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password17, EElen_password);
			return size;
            break;
		case 18:
			okeeprom_eeget_passwordlen18(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password18, EElen_password);
			return size;
            break;
		case 19:
			okeeprom_eeget_passwordlen19(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password19, EElen_password);
			return size;
            break;
		case 20:
			okeeprom_eeget_passwordlen20(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password20, EElen_password);
			return size;
            break;
		case 21:
			okeeprom_eeget_passwordlen21(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password21, EElen_password);
			return size;
            break;
		case 22:
			okeeprom_eeget_passwordlen22(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password22, EElen_password);
			return size;
            break;
		case 23:
			okeeprom_eeget_passwordlen23(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password23, EElen_password);
			return size;
            break;
		case 24:
			okeeprom_eeget_passwordlen24(&length);
			size = (int) length;
			if (size > EElen_password) size = EElen_password;
			okeeprom_eeget_common(ptr, EEpos_password24, EElen_password);
			return size;
            break;
	}

	return 0;

}
/*********************************/
/*********************************/
void okeeprom_eeset_password (uint8_t *ptr, int size, int slot) {

		switch (slot) {
			uint8_t length;
        	case 1:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password1, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen1(&length);
            break;
		case 2:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password2, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen2(&length);
            break;
		case 3:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password3, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen3(&length);
            break;
		case 4:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password4, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen4(&length);
            break;
		case 5:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password5, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen5(&length);
            break;
		case 6:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password6, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen6(&length);
            break;
		case 7:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password7, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen7(&length);
            break;
		case 8:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password8, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen8(&length);
            break;
		case 9:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password9, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen9(&length);
            break;
		case 10:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password10, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen10(&length);
            break;
		case 11:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password11, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen11(&length);
            break;
		case 12:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password12, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen12(&length);
            break;
            case 13:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password13, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen13(&length);
            break;
		case 14:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password14, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen14(&length);
            break;
		case 15:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password15, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen15(&length);
            break;
		case 16:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password16, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen16(&length);
            break;
		case 17:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password17, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen17(&length);
            break;
		case 18:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password18, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen18(&length);
            break;
		case 19:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password19, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen19(&length);
            break;
		case 20:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password20, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen20(&length);
            break;
		case 21:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password21, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen21(&length);
            break;
		case 22:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password22, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen22(&length);
            break;
		case 23:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password23, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen23(&length);
            break;
		case 24:

			if (size > EElen_password) size = EElen_password;
			okeeprom_eeset_common(ptr, EEpos_password24, EElen_password);
			length = (uint8_t) size;
			okeeprom_eeset_passwordlen24(&length);
            break;
	}

}
/*********************************/
/*********************************/
int okeeprom_eeget_addchar (uint8_t *ptr, int slot) {

	switch (slot) {
        	case 1:
			okeeprom_eeget_common(ptr, EEpos_addchar_1, EElen_addchar);
			return EElen_addchar;
            break;
		case 2:
			okeeprom_eeget_common(ptr, EEpos_addchar_2, EElen_addchar);
			return EElen_addchar;
            break;
		case 3:
			okeeprom_eeget_common(ptr, EEpos_addchar_3, EElen_addchar);
			return EElen_addchar;
            break;
		case 4:
			okeeprom_eeget_common(ptr, EEpos_addchar_4, EElen_addchar);
			return EElen_addchar;
            break;
		case 5:
			okeeprom_eeget_common(ptr, EEpos_addchar_5, EElen_addchar);
			return EElen_addchar;
            break;
		case 6:
			okeeprom_eeget_common(ptr, EEpos_addchar_6, EElen_addchar);
			return EElen_addchar;
            break;
		case 7:
			okeeprom_eeget_common(ptr, EEpos_addchar_7, EElen_addchar);
			return EElen_addchar;
            break;
		case 8:
			okeeprom_eeget_common(ptr, EEpos_addchar_8, EElen_addchar);
			return EElen_addchar;
            break;
		case 9:
			okeeprom_eeget_common(ptr, EEpos_addchar_9, EElen_addchar);
			return EElen_addchar;
            break;
		case 10:
			okeeprom_eeget_common(ptr, EEpos_addchar_10, EElen_addchar);
			return EElen_addchar;
            break;
		case 11:
			okeeprom_eeget_common(ptr, EEpos_addchar_11, EElen_addchar);
			return EElen_addchar;
            break;
		case 12:
			okeeprom_eeget_common(ptr, EEpos_addchar_12, EElen_addchar);
			return EElen_addchar;
            break;
		case 13:
			okeeprom_eeget_common(ptr, EEpos_addchar_13, EElen_addchar);
			return EElen_addchar;
            break;
		case 14:
			okeeprom_eeget_common(ptr, EEpos_addchar_14, EElen_addchar);
			return EElen_addchar;
            break;
		case 15:
			okeeprom_eeget_common(ptr, EEpos_addchar_15, EElen_addchar);
			return EElen_addchar;
            break;
		case 16:
			okeeprom_eeget_common(ptr, EEpos_addchar_16, EElen_addchar);
			return EElen_addchar;
            break;
		case 17:
			okeeprom_eeget_common(ptr, EEpos_addchar_17, EElen_addchar);
			return EElen_addchar;
            break;
		case 18:
			okeeprom_eeget_common(ptr, EEpos_addchar_18, EElen_addchar);
			return EElen_addchar;
            break;
		case 19:
			okeeprom_eeget_common(ptr, EEpos_addchar_19, EElen_addchar);
			return EElen_addchar;
            break;
		case 20:
			okeeprom_eeget_common(ptr, EEpos_addchar_20, EElen_addchar);
			return EElen_addchar;
            break;
		case 21:
			okeeprom_eeget_common(ptr, EEpos_addchar_21, EElen_addchar);
			return EElen_addchar;
            break;
		case 22:
			okeeprom_eeget_common(ptr, EEpos_addchar_22, EElen_addchar);
			return EElen_addchar;
            break;
		case 23:
			okeeprom_eeget_common(ptr, EEpos_addchar_23, EElen_addchar);
			return EElen_addchar;
            break;
		case 24:
			okeeprom_eeget_common(ptr, EEpos_addchar_24, EElen_addchar);
			return EElen_addchar;
            break;
	}

	return 0;

}
/*********************************/
/*********************************/
void okeeprom_eeset_addchar (uint8_t *ptr, int slot) {

		switch (slot) {

        	case 1:
		okeeprom_eeset_common(ptr, EEpos_addchar_1, EElen_addchar);
            break;
		case 2:
		okeeprom_eeset_common(ptr, EEpos_addchar_2, EElen_addchar);
            break;
		case 3:
		okeeprom_eeset_common(ptr, EEpos_addchar_3, EElen_addchar);
            break;
		case 4:
		okeeprom_eeset_common(ptr, EEpos_addchar_4, EElen_addchar);
            break;
		case 5:
		okeeprom_eeset_common(ptr, EEpos_addchar_5, EElen_addchar);
            break;
		case 6:
		okeeprom_eeset_common(ptr, EEpos_addchar_6, EElen_addchar);
            break;
		case 7:
		okeeprom_eeset_common(ptr, EEpos_addchar_7, EElen_addchar);
            break;
		case 8:
		okeeprom_eeset_common(ptr, EEpos_addchar_8, EElen_addchar);
            break;
		case 9:
		okeeprom_eeset_common(ptr, EEpos_addchar_9, EElen_addchar);
            break;
		case 10:
		okeeprom_eeset_common(ptr, EEpos_addchar_10, EElen_addchar);
            break;
		case 11:
		okeeprom_eeset_common(ptr, EEpos_addchar_11, EElen_addchar);
            break;
		case 12:
		okeeprom_eeset_common(ptr, EEpos_addchar_12, EElen_addchar);
            break;
		case 13:
		okeeprom_eeset_common(ptr, EEpos_addchar_13, EElen_addchar);
            break;
		case 14:
		okeeprom_eeset_common(ptr, EEpos_addchar_14, EElen_addchar);
            break;
		case 15:
		okeeprom_eeset_common(ptr, EEpos_addchar_15, EElen_addchar);
            break;
		case 16:
		okeeprom_eeset_common(ptr, EEpos_addchar_16, EElen_addchar);
            break;
		case 17:
		okeeprom_eeset_common(ptr, EEpos_addchar_17, EElen_addchar);
            break;
		case 18:
		okeeprom_eeset_common(ptr, EEpos_addchar_18, EElen_addchar);
            break;
		case 19:
		okeeprom_eeset_common(ptr, EEpos_addchar_19, EElen_addchar);
            break;
		case 20:
		okeeprom_eeset_common(ptr, EEpos_addchar_20, EElen_addchar);
            break;
		case 21:
		okeeprom_eeset_common(ptr, EEpos_addchar_21, EElen_addchar);
            break;
		case 22:
		okeeprom_eeset_common(ptr, EEpos_addchar_22, EElen_addchar);
            break;
		case 23:
		okeeprom_eeset_common(ptr, EEpos_addchar_23, EElen_addchar);
            break;
		case 24:
		okeeprom_eeset_common(ptr, EEpos_addchar_24, EElen_addchar);
            break;
	}

}
/*********************************/
/*********************************/
int okeeprom_eeget_delay1 (uint8_t *ptr, int slot) {

	switch (slot) {
        	case 1:
			okeeprom_eeget_common(ptr, EEpos_delay1_1, EElen_delay);
			return EElen_delay;
            break;
		case 2:
			okeeprom_eeget_common(ptr, EEpos_delay1_2, EElen_delay);
			return EElen_delay;
            break;
		case 3:
			okeeprom_eeget_common(ptr, EEpos_delay1_3, EElen_delay);
			return EElen_delay;
            break;
		case 4:
			okeeprom_eeget_common(ptr, EEpos_delay1_4, EElen_delay);
			return EElen_delay;
            break;
		case 5:
			okeeprom_eeget_common(ptr, EEpos_delay1_5, EElen_delay);
			return EElen_delay;
            break;
		case 6:
			okeeprom_eeget_common(ptr, EEpos_delay1_6, EElen_delay);
			return EElen_delay;
            break;
		case 7:
			okeeprom_eeget_common(ptr, EEpos_delay1_7, EElen_delay);
			return EElen_delay;
            break;
		case 8:
			okeeprom_eeget_common(ptr, EEpos_delay1_8, EElen_delay);
			return EElen_delay;
            break;
		case 9:
			okeeprom_eeget_common(ptr, EEpos_delay1_9, EElen_delay);
			return EElen_delay;
            break;
		case 10:
			okeeprom_eeget_common(ptr, EEpos_delay1_10, EElen_delay);
			return EElen_delay;
            break;
		case 11:
			okeeprom_eeget_common(ptr, EEpos_delay1_11, EElen_delay);
			return EElen_delay;
            break;
		case 12:
			okeeprom_eeget_common(ptr, EEpos_delay1_12, EElen_delay);
			return EElen_delay;
            break;
		case 13:
			okeeprom_eeget_common(ptr, EEpos_delay1_13, EElen_delay);
			return EElen_delay;
            break;
		case 14:
			okeeprom_eeget_common(ptr, EEpos_delay1_14, EElen_delay);
			return EElen_delay;
            break;
		case 15:
			okeeprom_eeget_common(ptr, EEpos_delay1_15, EElen_delay);
			return EElen_delay;
            break;
		case 16:
			okeeprom_eeget_common(ptr, EEpos_delay1_16, EElen_delay);
			return EElen_delay;
            break;
		case 17:
			okeeprom_eeget_common(ptr, EEpos_delay1_17, EElen_delay);
			return EElen_delay;
            break;
		case 18:
			okeeprom_eeget_common(ptr, EEpos_delay1_18, EElen_delay);
			return EElen_delay;
            break;
		case 19:
			okeeprom_eeget_common(ptr, EEpos_delay1_19, EElen_delay);
			return EElen_delay;
            break;
		case 20:
			okeeprom_eeget_common(ptr, EEpos_delay1_20, EElen_delay);
			return EElen_delay;
            break;
		case 21:
			okeeprom_eeget_common(ptr, EEpos_delay1_21, EElen_delay);
			return EElen_delay;
            break;
		case 22:
			okeeprom_eeget_common(ptr, EEpos_delay1_22, EElen_delay);
			return EElen_delay;
            break;
		case 23:
			okeeprom_eeget_common(ptr, EEpos_delay1_23, EElen_delay);
			return EElen_delay;
            break;
		case 24:
			okeeprom_eeget_common(ptr, EEpos_delay1_24, EElen_delay);
			return EElen_delay;
            break;
	}

	return 0;

}
/*********************************/
/*********************************/
void okeeprom_eeset_delay1 (uint8_t *ptr, int slot) {

		switch (slot) {

        	case 1:
		okeeprom_eeset_common(ptr, EEpos_delay1_1, EElen_delay);
            break;
		case 2:
		okeeprom_eeset_common(ptr, EEpos_delay1_2, EElen_delay);
            break;
		case 3:
		okeeprom_eeset_common(ptr, EEpos_delay1_3, EElen_delay);
            break;
		case 4:
		okeeprom_eeset_common(ptr, EEpos_delay1_4, EElen_delay);
            break;
		case 5:
		okeeprom_eeset_common(ptr, EEpos_delay1_5, EElen_delay);
            break;
		case 6:
		okeeprom_eeset_common(ptr, EEpos_delay1_6, EElen_delay);
            break;
		case 7:
		okeeprom_eeset_common(ptr, EEpos_delay1_7, EElen_delay);
            break;
		case 8:
		okeeprom_eeset_common(ptr, EEpos_delay1_8, EElen_delay);
            break;
		case 9:
		okeeprom_eeset_common(ptr, EEpos_delay1_9, EElen_delay);
            break;
		case 10:
		okeeprom_eeset_common(ptr, EEpos_delay1_10, EElen_delay);
            break;
		case 11:
		okeeprom_eeset_common(ptr, EEpos_delay1_11, EElen_delay);
            break;
		case 12:
		okeeprom_eeset_common(ptr, EEpos_delay1_12, EElen_delay);
            break;
        case 13:
		okeeprom_eeset_common(ptr, EEpos_delay1_13, EElen_delay);
            break;
		case 14:
		okeeprom_eeset_common(ptr, EEpos_delay1_14, EElen_delay);
            break;
		case 15:
		okeeprom_eeset_common(ptr, EEpos_delay1_15, EElen_delay);
            break;
		case 16:
		okeeprom_eeset_common(ptr, EEpos_delay1_16, EElen_delay);
            break;
		case 17:
		okeeprom_eeset_common(ptr, EEpos_delay1_17, EElen_delay);
            break;
		case 18:
		okeeprom_eeset_common(ptr, EEpos_delay1_18, EElen_delay);
            break;
		case 19:
		okeeprom_eeset_common(ptr, EEpos_delay1_19, EElen_delay);
            break;
		case 20:
		okeeprom_eeset_common(ptr, EEpos_delay1_20, EElen_delay);
            break;
		case 21:
		okeeprom_eeset_common(ptr, EEpos_delay1_21, EElen_delay);
            break;
		case 22:
		okeeprom_eeset_common(ptr, EEpos_delay1_22, EElen_delay);
            break;
		case 23:
		okeeprom_eeset_common(ptr, EEpos_delay1_23, EElen_delay);
            break;
		case 24:
		okeeprom_eeset_common(ptr, EEpos_delay1_24, EElen_delay);
            break;
	}

}
/*********************************/
/*********************************/
int okeeprom_eeget_delay2 (uint8_t *ptr, int slot) {

	switch (slot) {
        case 1:
			okeeprom_eeget_common(ptr, EEpos_delay2_1, EElen_delay);
			return EElen_delay;
            break;
		case 2:
			okeeprom_eeget_common(ptr, EEpos_delay2_2, EElen_delay);
			return EElen_delay;
            break;
		case 3:
			okeeprom_eeget_common(ptr, EEpos_delay2_3, EElen_delay);
			return EElen_delay;
            break;
		case 4:
			okeeprom_eeget_common(ptr, EEpos_delay2_4, EElen_delay);
			return EElen_delay;
            break;
		case 5:
			okeeprom_eeget_common(ptr, EEpos_delay2_5, EElen_delay);
			return EElen_delay;
            break;
		case 6:
			okeeprom_eeget_common(ptr, EEpos_delay2_6, EElen_delay);
			return EElen_delay;
            break;
		case 7:
			okeeprom_eeget_common(ptr, EEpos_delay2_7, EElen_delay);
			return EElen_delay;
            break;
		case 8:
			okeeprom_eeget_common(ptr, EEpos_delay2_8, EElen_delay);
			return EElen_delay;
            break;
		case 9:
			okeeprom_eeget_common(ptr, EEpos_delay2_9, EElen_delay);
			return EElen_delay;
            break;
		case 10:
			okeeprom_eeget_common(ptr, EEpos_delay2_10, EElen_delay);
			return EElen_delay;
            break;
		case 11:
			okeeprom_eeget_common(ptr, EEpos_delay2_11, EElen_delay);
			return EElen_delay;
            break;
		case 12:
			okeeprom_eeget_common(ptr, EEpos_delay2_12, EElen_delay);
			return EElen_delay;
            break;
		case 13:
			okeeprom_eeget_common(ptr, EEpos_delay2_13, EElen_delay);
			return EElen_delay;
            break;
		case 14:
			okeeprom_eeget_common(ptr, EEpos_delay2_14, EElen_delay);
			return EElen_delay;
            break;
		case 15:
			okeeprom_eeget_common(ptr, EEpos_delay2_15, EElen_delay);
			return EElen_delay;
            break;
		case 16:
			okeeprom_eeget_common(ptr, EEpos_delay2_16, EElen_delay);
			return EElen_delay;
            break;
		case 17:
			okeeprom_eeget_common(ptr, EEpos_delay2_17, EElen_delay);
			return EElen_delay;
            break;
		case 18:
			okeeprom_eeget_common(ptr, EEpos_delay2_18, EElen_delay);
			return EElen_delay;
            break;
		case 19:
			okeeprom_eeget_common(ptr, EEpos_delay2_19, EElen_delay);
			return EElen_delay;
            break;
		case 20:
			okeeprom_eeget_common(ptr, EEpos_delay2_20, EElen_delay);
			return EElen_delay;
            break;
		case 21:
			okeeprom_eeget_common(ptr, EEpos_delay2_21, EElen_delay);
			return EElen_delay;
            break;
		case 22:
			okeeprom_eeget_common(ptr, EEpos_delay2_22, EElen_delay);
			return EElen_delay;
            break;
		case 23:
			okeeprom_eeget_common(ptr, EEpos_delay2_23, EElen_delay);
			return EElen_delay;
            break;
		case 24:
			okeeprom_eeget_common(ptr, EEpos_delay2_24, EElen_delay);
			return EElen_delay;
            break;

	}

	return 0;

}
/*********************************/
/*********************************/
void okeeprom_eeset_delay2 (uint8_t *ptr, int slot) {

		switch (slot) {

        case 1:
		okeeprom_eeset_common(ptr, EEpos_delay2_1, EElen_delay);
            break;
		case 2:
		okeeprom_eeset_common(ptr, EEpos_delay2_2, EElen_delay);
            break;
		case 3:
		okeeprom_eeset_common(ptr, EEpos_delay2_3, EElen_delay);
            break;
		case 4:
		okeeprom_eeset_common(ptr, EEpos_delay2_4, EElen_delay);
            break;
		case 5:
		okeeprom_eeset_common(ptr, EEpos_delay2_5, EElen_delay);
            break;
		case 6:
		okeeprom_eeset_common(ptr, EEpos_delay2_6, EElen_delay);
            break;
		case 7:
		okeeprom_eeset_common(ptr, EEpos_delay2_7, EElen_delay);
            break;
		case 8:
		okeeprom_eeset_common(ptr, EEpos_delay2_8, EElen_delay);
            break;
		case 9:
		okeeprom_eeset_common(ptr, EEpos_delay2_9, EElen_delay);
            break;
		case 10:
		okeeprom_eeset_common(ptr, EEpos_delay2_10, EElen_delay);
            break;
		case 11:
		okeeprom_eeset_common(ptr, EEpos_delay2_11, EElen_delay);
            break;
		case 12:
		okeeprom_eeset_common(ptr, EEpos_delay2_12, EElen_delay);
            break;
		case 13:
		okeeprom_eeset_common(ptr, EEpos_delay2_13, EElen_delay);
            break;
		case 14:
		okeeprom_eeset_common(ptr, EEpos_delay2_14, EElen_delay);
            break;
		case 15:
		okeeprom_eeset_common(ptr, EEpos_delay2_15, EElen_delay);
            break;
		case 16:
		okeeprom_eeset_common(ptr, EEpos_delay2_16, EElen_delay);
            break;
		case 17:
		okeeprom_eeset_common(ptr, EEpos_delay2_17, EElen_delay);
            break;
		case 18:
		okeeprom_eeset_common(ptr, EEpos_delay2_18, EElen_delay);
            break;
		case 19:
		okeeprom_eeset_common(ptr, EEpos_delay2_19, EElen_delay);
            break;
		case 20:
		okeeprom_eeset_common(ptr, EEpos_delay2_20, EElen_delay);
            break;
		case 21:
		okeeprom_eeset_common(ptr, EEpos_delay2_21, EElen_delay);
            break;
		case 22:
		okeeprom_eeset_common(ptr, EEpos_delay2_22, EElen_delay);
            break;
		case 23:
		okeeprom_eeset_common(ptr, EEpos_delay2_23, EElen_delay);
            break;
		case 24:
		okeeprom_eeset_common(ptr, EEpos_delay2_24, EElen_delay);
            break;

	}

}
/*********************************/
/*********************************/
int okeeprom_eeget_delay3 (uint8_t *ptr, int slot) {

	switch (slot) {
        case 1:
			okeeprom_eeget_common(ptr, EEpos_delay3_1, EElen_delay);
			return EElen_delay;
            break;
		case 2:
			okeeprom_eeget_common(ptr, EEpos_delay3_2, EElen_delay);
			return EElen_delay;
            break;
		case 3:
			okeeprom_eeget_common(ptr, EEpos_delay3_3, EElen_delay);
			return EElen_delay;
            break;
		case 4:
			okeeprom_eeget_common(ptr, EEpos_delay3_4, EElen_delay);
			return EElen_delay;
            break;
		case 5:
			okeeprom_eeget_common(ptr, EEpos_delay3_5, EElen_delay);
			return EElen_delay;
            break;
		case 6:
			okeeprom_eeget_common(ptr, EEpos_delay3_6, EElen_delay);
			return EElen_delay;
            break;
		case 7:
			okeeprom_eeget_common(ptr, EEpos_delay3_7, EElen_delay);
			return EElen_delay;
            break;
		case 8:
			okeeprom_eeget_common(ptr, EEpos_delay3_8, EElen_delay);
			return EElen_delay;
            break;
		case 9:
			okeeprom_eeget_common(ptr, EEpos_delay3_9, EElen_delay);
			return EElen_delay;
            break;
		case 10:
			okeeprom_eeget_common(ptr, EEpos_delay3_10, EElen_delay);
			return EElen_delay;
            break;
		case 11:
			okeeprom_eeget_common(ptr, EEpos_delay3_11, EElen_delay);
			return EElen_delay;
            break;
		case 12:
			okeeprom_eeget_common(ptr, EEpos_delay3_12, EElen_delay);
			return EElen_delay;
            break;
		case 13:
			okeeprom_eeget_common(ptr, EEpos_delay3_13, EElen_delay);
			return EElen_delay;
            break;
		case 14:
			okeeprom_eeget_common(ptr, EEpos_delay3_14, EElen_delay);
			return EElen_delay;
            break;
		case 15:
			okeeprom_eeget_common(ptr, EEpos_delay3_15, EElen_delay);
			return EElen_delay;
            break;
		case 16:
			okeeprom_eeget_common(ptr, EEpos_delay3_16, EElen_delay);
			return EElen_delay;
            break;
		case 17:
			okeeprom_eeget_common(ptr, EEpos_delay3_17, EElen_delay);
			return EElen_delay;
            break;
		case 18:
			okeeprom_eeget_common(ptr, EEpos_delay3_18, EElen_delay);
			return EElen_delay;
            break;
		case 19:
			okeeprom_eeget_common(ptr, EEpos_delay3_19, EElen_delay);
			return EElen_delay;
            break;
		case 20:
			okeeprom_eeget_common(ptr, EEpos_delay3_20, EElen_delay);
			return EElen_delay;
            break;
		case 21:
			okeeprom_eeget_common(ptr, EEpos_delay3_21, EElen_delay);
			return EElen_delay;
            break;
		case 22:
			okeeprom_eeget_common(ptr, EEpos_delay3_22, EElen_delay);
			return EElen_delay;
            break;
		case 23:
			okeeprom_eeget_common(ptr, EEpos_delay3_23, EElen_delay);
			return EElen_delay;
            break;
		case 24:
			okeeprom_eeget_common(ptr, EEpos_delay3_24, EElen_delay);
			return EElen_delay;
            break;

	}

	return 0;

}
/*********************************/
/*********************************/
void okeeprom_eeset_delay3 (uint8_t *ptr, int slot) {

		switch (slot) {

        case 1:
		okeeprom_eeset_common(ptr, EEpos_delay3_1, EElen_delay);
            break;
		case 2:
		okeeprom_eeset_common(ptr, EEpos_delay3_2, EElen_delay);
            break;
		case 3:
		okeeprom_eeset_common(ptr, EEpos_delay3_3, EElen_delay);
            break;
		case 4:
		okeeprom_eeset_common(ptr, EEpos_delay3_4, EElen_delay);
            break;
		case 5:
		okeeprom_eeset_common(ptr, EEpos_delay3_5, EElen_delay);
            break;
		case 6:
		okeeprom_eeset_common(ptr, EEpos_delay3_6, EElen_delay);
            break;
		case 7:
		okeeprom_eeset_common(ptr, EEpos_delay3_7, EElen_delay);
            break;
		case 8:
		okeeprom_eeset_common(ptr, EEpos_delay3_8, EElen_delay);
            break;
		case 9:
		okeeprom_eeset_common(ptr, EEpos_delay3_9, EElen_delay);
            break;
		case 10:
		okeeprom_eeset_common(ptr, EEpos_delay3_10, EElen_delay);
            break;
		case 11:
		okeeprom_eeset_common(ptr, EEpos_delay3_11, EElen_delay);
            break;
		case 12:
		okeeprom_eeset_common(ptr, EEpos_delay3_12, EElen_delay);
            break;
		case 13:
		okeeprom_eeset_common(ptr, EEpos_delay3_13, EElen_delay);
            break;
		case 14:
		okeeprom_eeset_common(ptr, EEpos_delay3_14, EElen_delay);
            break;
		case 15:
		okeeprom_eeset_common(ptr, EEpos_delay3_15, EElen_delay);
            break;
		case 16:
		okeeprom_eeset_common(ptr, EEpos_delay3_16, EElen_delay);
            break;
		case 17:
		okeeprom_eeset_common(ptr, EEpos_delay3_17, EElen_delay);
            break;
		case 18:
		okeeprom_eeset_common(ptr, EEpos_delay3_18, EElen_delay);
            break;
		case 19:
		okeeprom_eeset_common(ptr, EEpos_delay3_19, EElen_delay);
            break;
		case 20:
		okeeprom_eeset_common(ptr, EEpos_delay3_20, EElen_delay);
            break;
		case 21:
		okeeprom_eeset_common(ptr, EEpos_delay3_21, EElen_delay);
            break;
		case 22:
		okeeprom_eeset_common(ptr, EEpos_delay3_22, EElen_delay);
            break;
		case 23:
		okeeprom_eeset_common(ptr, EEpos_delay3_23, EElen_delay);
            break;
		case 24:
		okeeprom_eeset_common(ptr, EEpos_delay3_24, EElen_delay);
            break;

	}

}
/*********************************/
/*********************************/
int okeeprom_eeget_2FAtype (uint8_t *ptr, int slot) {

	switch (slot) {
        	case 1:
			okeeprom_eeget_common(ptr, EEpos_2FAtype1, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 2:
			okeeprom_eeget_common(ptr, EEpos_2FAtype2, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 3:
			okeeprom_eeget_common(ptr, EEpos_2FAtype3, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 4:
			okeeprom_eeget_common(ptr, EEpos_2FAtype4, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 5:
			okeeprom_eeget_common(ptr, EEpos_2FAtype5, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 6:
			okeeprom_eeget_common(ptr, EEpos_2FAtype6, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 7:
			okeeprom_eeget_common(ptr, EEpos_2FAtype7, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 8:
			okeeprom_eeget_common(ptr, EEpos_2FAtype8, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 9:
			okeeprom_eeget_common(ptr, EEpos_2FAtype9, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 10:
			okeeprom_eeget_common(ptr, EEpos_2FAtype10, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 11:
			okeeprom_eeget_common(ptr, EEpos_2FAtype11, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 12:
			okeeprom_eeget_common(ptr, EEpos_2FAtype12, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 13:
			okeeprom_eeget_common(ptr, EEpos_2FAtype13, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 14:
			okeeprom_eeget_common(ptr, EEpos_2FAtype14, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 15:
			okeeprom_eeget_common(ptr, EEpos_2FAtype15, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 16:
			okeeprom_eeget_common(ptr, EEpos_2FAtype16, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 17:
			okeeprom_eeget_common(ptr, EEpos_2FAtype17, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 18:
			okeeprom_eeget_common(ptr, EEpos_2FAtype18, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 19:
			okeeprom_eeget_common(ptr, EEpos_2FAtype19, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 20:
			okeeprom_eeget_common(ptr, EEpos_2FAtype20, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 21:
			okeeprom_eeget_common(ptr, EEpos_2FAtype21, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 22:
			okeeprom_eeget_common(ptr, EEpos_2FAtype22, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 23:
			okeeprom_eeget_common(ptr, EEpos_2FAtype23, EElen_2FAtype);
			return EElen_2FAtype;
            break;
		case 24:
			okeeprom_eeget_common(ptr, EEpos_2FAtype24, EElen_2FAtype);
			return EElen_2FAtype;
            break;

	}

	return 0;

}
/*********************************/
/*********************************/
void okeeprom_eeset_2FAtype (uint8_t *ptr, int slot) {

		switch (slot) {

        case 1:
		okeeprom_eeset_common(ptr, EEpos_2FAtype1, EElen_2FAtype);
            break;
		case 2:
		okeeprom_eeset_common(ptr, EEpos_2FAtype2, EElen_2FAtype);
            break;
		case 3:
		okeeprom_eeset_common(ptr, EEpos_2FAtype3, EElen_2FAtype);
            break;
		case 4:
		okeeprom_eeset_common(ptr, EEpos_2FAtype4, EElen_2FAtype);
            break;
		case 5:
		okeeprom_eeset_common(ptr, EEpos_2FAtype5, EElen_2FAtype);
            break;
		case 6:
		okeeprom_eeset_common(ptr, EEpos_2FAtype6, EElen_2FAtype);
            break;
		case 7:
		okeeprom_eeset_common(ptr, EEpos_2FAtype7, EElen_2FAtype);
            break;
		case 8:
		okeeprom_eeset_common(ptr, EEpos_2FAtype8, EElen_2FAtype);
            break;
		case 9:
		okeeprom_eeset_common(ptr, EEpos_2FAtype9, EElen_2FAtype);
            break;
		case 10:
		okeeprom_eeset_common(ptr, EEpos_2FAtype10, EElen_2FAtype);
            break;
		case 11:
		okeeprom_eeset_common(ptr, EEpos_2FAtype11, EElen_2FAtype);
            break;
		case 12:
		okeeprom_eeset_common(ptr, EEpos_2FAtype12, EElen_2FAtype);
            break;
        case 13:
		okeeprom_eeset_common(ptr, EEpos_2FAtype13, EElen_2FAtype);
            break;
		case 14:
		okeeprom_eeset_common(ptr, EEpos_2FAtype14, EElen_2FAtype);
            break;
		case 15:
		okeeprom_eeset_common(ptr, EEpos_2FAtype15, EElen_2FAtype);
            break;
		case 16:
		okeeprom_eeset_common(ptr, EEpos_2FAtype16, EElen_2FAtype);
            break;
		case 17:
		okeeprom_eeset_common(ptr, EEpos_2FAtype17, EElen_2FAtype);
            break;
		case 18:
		okeeprom_eeset_common(ptr, EEpos_2FAtype18, EElen_2FAtype);
            break;
		case 19:
		okeeprom_eeset_common(ptr, EEpos_2FAtype19, EElen_2FAtype);
            break;
		case 20:
		okeeprom_eeset_common(ptr, EEpos_2FAtype20, EElen_2FAtype);
            break;
		case 21:
		okeeprom_eeset_common(ptr, EEpos_2FAtype21, EElen_2FAtype);
            break;
		case 22:
		okeeprom_eeset_common(ptr, EEpos_2FAtype22, EElen_2FAtype);
            break;
		case 23:
		okeeprom_eeset_common(ptr, EEpos_2FAtype23, EElen_2FAtype);
            break;
		case 24:
		okeeprom_eeset_common(ptr, EEpos_2FAtype24, EElen_2FAtype);
            break;
	}

}
/*********************************/
/*********************************/
int okeeprom_eeget_ecckey (uint8_t *ptr, int slot) {

	switch (slot) {
        case 101:
			okeeprom_eeget_common(ptr, EEpos_ecckey1, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 102:
			okeeprom_eeget_common(ptr, EEpos_ecckey2, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 103:
			okeeprom_eeget_common(ptr, EEpos_ecckey3, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 104:
			okeeprom_eeget_common(ptr, EEpos_ecckey4, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 105:
			okeeprom_eeget_common(ptr, EEpos_ecckey5, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 106:
			okeeprom_eeget_common(ptr, EEpos_ecckey6, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 107:
			okeeprom_eeget_common(ptr, EEpos_ecckey7, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 108:
			okeeprom_eeget_common(ptr, EEpos_ecckey8, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 109:
			okeeprom_eeget_common(ptr, EEpos_ecckey9, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 110:
			okeeprom_eeget_common(ptr, EEpos_ecckey10, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 111:
			okeeprom_eeget_common(ptr, EEpos_ecckey11, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 112:
			okeeprom_eeget_common(ptr, EEpos_ecckey12, EElen_ecckey);
			return EElen_ecckey;
            break;
        case 113:
			okeeprom_eeget_common(ptr, EEpos_ecckey13, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 114:
			okeeprom_eeget_common(ptr, EEpos_ecckey14, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 115:
			okeeprom_eeget_common(ptr, EEpos_ecckey15, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 116:
			okeeprom_eeget_common(ptr, EEpos_ecckey16, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 117:
			okeeprom_eeget_common(ptr, EEpos_ecckey17, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 118:
			okeeprom_eeget_common(ptr, EEpos_ecckey18, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 119:
			okeeprom_eeget_common(ptr, EEpos_ecckey19, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 120:
			okeeprom_eeget_common(ptr, EEpos_ecckey20, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 121:
			okeeprom_eeget_common(ptr, EEpos_ecckey21, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 122:
			okeeprom_eeget_common(ptr, EEpos_ecckey22, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 123:
			okeeprom_eeget_common(ptr, EEpos_ecckey23, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 124:
			okeeprom_eeget_common(ptr, EEpos_ecckey24, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 125:
			okeeprom_eeget_common(ptr, EEpos_ecckey25, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 126:
			okeeprom_eeget_common(ptr, EEpos_ecckey26, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 127:
			okeeprom_eeget_common(ptr, EEpos_ecckey27, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 128:
			okeeprom_eeget_common(ptr, EEpos_ecckey28, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 129:
			okeeprom_eeget_common(ptr, EEpos_ecckey29, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 130:
			okeeprom_eeget_common(ptr, EEpos_ecckey30, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 131:
			okeeprom_eeget_common(ptr, EEpos_ecckey31, EElen_ecckey);
			return EElen_ecckey;
            break;
		case 132:
			okeeprom_eeget_common(ptr, EEpos_ecckey32, EElen_ecckey);
			return EElen_ecckey;
            break;
	}

	return 0;

}
/*********************************/
/*********************************/
void okeeprom_eeset_ecckey (uint8_t *ptr, int slot) {

		switch (slot) {

        case 101:
		okeeprom_eeset_common(ptr, EEpos_ecckey1, EElen_ecckey);
            break;
		case 102:
		okeeprom_eeset_common(ptr, EEpos_ecckey2, EElen_ecckey);
            break;
		case 103:
		okeeprom_eeset_common(ptr, EEpos_ecckey3, EElen_ecckey);
            break;
		case 104:
		okeeprom_eeset_common(ptr, EEpos_ecckey4, EElen_ecckey);
            break;
		case 105:
		okeeprom_eeset_common(ptr, EEpos_ecckey5, EElen_ecckey);
            break;
		case 106:
		okeeprom_eeset_common(ptr, EEpos_ecckey6, EElen_ecckey);
            break;
		case 107:
		okeeprom_eeset_common(ptr, EEpos_ecckey7, EElen_ecckey);
            break;
		case 108:
		okeeprom_eeset_common(ptr, EEpos_ecckey8, EElen_ecckey);
            break;
		case 109:
		okeeprom_eeset_common(ptr, EEpos_ecckey9, EElen_ecckey);
            break;
		case 110:
		okeeprom_eeset_common(ptr, EEpos_ecckey10, EElen_ecckey);
            break;
		case 111:
		okeeprom_eeset_common(ptr, EEpos_ecckey11, EElen_ecckey);
            break;
		case 112:
		okeeprom_eeset_common(ptr, EEpos_ecckey12, EElen_ecckey);
            break;
        case 113:
		okeeprom_eeset_common(ptr, EEpos_ecckey13, EElen_ecckey);
            break;
		case 114:
		okeeprom_eeset_common(ptr, EEpos_ecckey14, EElen_ecckey);
            break;
		case 115:
		okeeprom_eeset_common(ptr, EEpos_ecckey15, EElen_ecckey);
            break;
		case 116:
		okeeprom_eeset_common(ptr, EEpos_ecckey16, EElen_ecckey);
            break;
		case 117:
		okeeprom_eeset_common(ptr, EEpos_ecckey17, EElen_ecckey);
            break;
		case 118:
		okeeprom_eeset_common(ptr, EEpos_ecckey18, EElen_ecckey);
            break;
		case 119:
		okeeprom_eeset_common(ptr, EEpos_ecckey19, EElen_ecckey);
            break;
		case 120:
		okeeprom_eeset_common(ptr, EEpos_ecckey20, EElen_ecckey);
            break;
		case 121:
		okeeprom_eeset_common(ptr, EEpos_ecckey21, EElen_ecckey);
            break;
		case 122:
		okeeprom_eeset_common(ptr, EEpos_ecckey22, EElen_ecckey);
            break;
		case 123:
		okeeprom_eeset_common(ptr, EEpos_ecckey23, EElen_ecckey);
            break;
		case 124:
		okeeprom_eeset_common(ptr, EEpos_ecckey24, EElen_ecckey);
            break;
		case 125:
		okeeprom_eeset_common(ptr, EEpos_ecckey25, EElen_ecckey);
            break;
		case 126:
		okeeprom_eeset_common(ptr, EEpos_ecckey26, EElen_ecckey);
            break;
		case 127:
		okeeprom_eeset_common(ptr, EEpos_ecckey27, EElen_ecckey);
            break;
		case 128:
		okeeprom_eeset_common(ptr, EEpos_ecckey28, EElen_ecckey);
            break;
		case 129:
		okeeprom_eeset_common(ptr, EEpos_ecckey29, EElen_ecckey);
            break;
		case 130:
		okeeprom_eeset_common(ptr, EEpos_ecckey30, EElen_ecckey);
            break;
		case 131:
		okeeprom_eeset_common(ptr, EEpos_ecckey31, EElen_ecckey);
            break;
		case 132:
		okeeprom_eeset_common(ptr, EEpos_ecckey32, EElen_ecckey);
            break;
	}

}
/*********************************/
/*********************************/
int okeeprom_eeget_rsakey (uint8_t *ptr, int slot) {

	switch (slot) {
		case 1:
			okeeprom_eeget_common(ptr, EEpos_rsakey1, EElen_rsakey);
			return EElen_rsakey;
            break;
		case 2:
			okeeprom_eeget_common(ptr, EEpos_rsakey2, EElen_rsakey);
			return EElen_rsakey;
            break;
		case 3:
			okeeprom_eeget_common(ptr, EEpos_rsakey3, EElen_rsakey);
			return EElen_rsakey;
            break;
		case 4:
			okeeprom_eeget_common(ptr, EEpos_rsakey4, EElen_rsakey);
			return EElen_rsakey;
            break;
	}

	return 0;

}
/*********************************/
/*********************************/
void okeeprom_eeset_rsakey (uint8_t *ptr, int slot) {

		switch (slot) {

		case 1:
		okeeprom_eeset_common(ptr, EEpos_rsakey1, EElen_rsakey);
            break;
		case 2:
		okeeprom_eeset_common(ptr, EEpos_rsakey2, EElen_rsakey);
            break;
		case 3:
		okeeprom_eeset_common(ptr, EEpos_rsakey3, EElen_rsakey);
            break;
		case 4:
		okeeprom_eeset_common(ptr, EEpos_rsakey4, EElen_rsakey);
            break;
	}

}
/*********************************/

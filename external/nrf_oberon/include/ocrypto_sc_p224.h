/**
 * Copyright (c) 2021, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef OCRYPTO_SC_P224_H
#define OCRYPTO_SC_P224_H

#include <stddef.h>
#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif

/**@cond */

// P-224 scalar modulo group order
typedef struct {
    uint32_t w[7]; // little endian
} ocrypto_sc_p224;


// modulo P-224 number
typedef struct {
  uint32_t w[7]; // little endian
} ocrypto_mod_p224;
/**@endcond */

// scalar to 28 byte value
void ocrypto_sc_p224_to28bytes(uint8_t r[28], const ocrypto_sc_p224 *x);

// 28 byte value to scalar
// return 0 if x < group order
int ocrypto_sc_p224_from28bytes(ocrypto_sc_p224 *r, const uint8_t x[28]);

// reduce 36 bytes to range 0 < r < group order
void ocrypto_sc_p224_from36bytes(ocrypto_sc_p224 *r, const uint8_t x[36]);


#ifdef __cplusplus
}
#endif

#endif /* #ifndef OCRYPTO_SC_P224_H */

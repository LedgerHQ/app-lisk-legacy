/** ******************************************************************************
 *  (c) 2018 - 2022 Zondax AG
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ******************************************************************************* */
export const CLA = 0x60;
export const enum INS {
  GET_VERSION = 0x00,
  GET_ADDR_PUBKEY = 0x01,
  SIGN_TXN = 0x02,
  SIGN_MSG = 0x03,
  CLAIM_MSG = 0x04,
}
export const PKLEN = 32;

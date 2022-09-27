/*******************************************************************************
*   (c) 2018 - 2022 Zondax AG
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
********************************************************************************/

// #{TODO} --> Apply tests that check this app's encoding/libraries

#include "gmock/gmock.h"

#include <vector>
#include <iostream>
#include <hexutils.h>
#include "parser_txdef.h"
#include "parser.h"
#include "parser_impl.h"

#include "crypto_helper.h"

using namespace std;


TEST(Address, Lisk32Encoding) {

    std::vector<string> pubkeys {"0eb0a6d7b862dc35c856c02c47fde3b4f60f2f3571a888b9a8ca7540c6793243",
                                 "0000000000000000000000000000000000000000000000000000000000000000",
                                 "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
                                 "00ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
                                 "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff00",
                                 "749b88baa787e83b5a06bbfee95002ac5a9925dcaeea28262e683498147b8fce",
                                 "e877c250d725ac7ca6c5d9d83b39645de7eebe6c4ae6e076da7163434d297c7d"};

    std::vector<string> addresses { "lsk24cd35u4jdq8szo3pnsqe5dsxwrnazyqqqg5eu",
                                    "lskoaknq582o6fw7sp82bm2hnj7pzp47mpmbmux2g",
                                    "lskqf5xbhu874yqg89k449zk2fctj46fona9bafgr",
                                    "lskamc9kfzenupkgexyxsf4qz9fv8mo9432of9p5j",
                                    "lsk6xevdsz3dpqfsx2u6mg3jx9zk8xqdozvn7x5ur",
                                    "lskxwnb4ubt93gz49w3of855yy9uzntddyndahm6s",
                                    "lskzkfw7ofgp3uusknbetemrey4aeatgf2ntbhcds"};

    const uint8_t LISK32_SIZE{41};

    for (uint8_t i = 0; i < pubkeys.size(); i++) {
        uint8_t pubkey_buffer[100];
        auto bufferLen = parseHexString(
                pubkey_buffer,
                sizeof(pubkey_buffer),
                pubkeys.at(i).c_str()
        );
        uint8_t encoded[LISK32_SIZE] = {0};
        uint8_t address_len = 0;
        crypto_encodePubkey(encoded, LISK32_SIZE, pubkey_buffer, &address_len);
        EXPECT_EQ(address_len, LISK32_SIZE);

        std::string lisk32_address( encoded, encoded + LISK32_SIZE );
        EXPECT_EQ(lisk32_address, addresses.at(i));
    }
}

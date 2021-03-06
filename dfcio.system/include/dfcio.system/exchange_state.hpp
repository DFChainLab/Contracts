#pragma once

#include <fsciolib/asset.hpp>

namespace fsciosystem {
   using fscio::asset;
   using fscio::symbol;

   typedef double real_type;

   /**
    *  Uses Bancor math to create a 50/50 relay between two asset types. The state of the
    *  bancor exchange is entirely contained within this struct. There are no external
    *  side effects associated with using this API.
    */
   struct [[fscio::table, fscio::contract("fscio.system")]] exchange_state {
      asset    supply;

      struct connector {
         asset balance;
         double weight = .5;

         FSCLIB_SERIALIZE( connector, (balance)(weight) )
      };

      connector base;
      connector quote;

      uint64_t primary_key()const { return supply.symbol.raw(); }

      asset convert_to_exchange( connector& c, asset in );
      asset convert_from_exchange( connector& c, asset in );
      asset convert( asset from, const symbol& to );

      FSCLIB_SERIALIZE( exchange_state, (supply)(base)(quote) )
   };

   typedef fscio::multi_index< "rammarket"_n, exchange_state > rammarket;

} /// namespace fsciosystem

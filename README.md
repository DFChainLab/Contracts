# dfcio.contracts

## Version : 1.0.2

The design of the DFCIO blockchain calls for a number of smart contracts that are run at a privileged permission level in order to support functions such as block producer registration and voting, token staking for CPU and network bandwidth, RAM purchasing, multi-sig, etc.  These smart contracts are referred to as the system, token, msig and wrap (formerly known as sudo) contracts.

This repository contains examples of these privileged contracts that are useful when deploying, managing, and/or using an DFCIO blockchain.  They are provided for reference purposes:

   * dfcio.system
   * dfcio.msig
   * dfcio.wrap

The following unprivileged contract(s) are also part of the system.
   * dfcio.token

Dependencies:
* dfcio v1.0.x to v1.0.x
* dfcio.cdt v1.0.x to v1.0.x

To build the contracts and the unit tests:
* First, ensure that your __dfcio__ is compiled to the core symbol for the DFCIO blockchain that intend to deploy to.
* Second, make sure that you have ```sudo make install```ed __dfcio__.
* Then just run the ```build.sh``` in the top directory to build all the contracts and the unit tests for these contracts.

After build:
* The contracts are built into a _bin/\<contract name\>_ folder in their respective directories.
* Finally, simply use __cldfc__ to _set contract_ by pointing to the previously mentioned directory.

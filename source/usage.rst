
Usage
=====

Interactive Mode
----------------

.. code-block:: bash

   $ ./hsh
   ($) /bin/ls
   hsh main.c shell.c shell.h
   ($) exit
   $

Non-Interactive Mode
---------------------

.. code-block:: bash

   $ echo "/bin/ls" | ./hsh
   hsh main.c shell.c shell.h
   $
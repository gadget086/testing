TESTS = tests/unit_hello
AM_CFLAGS=-I${top_srcdir}/src -std=c99 -Wall
AM_LGFLAGS=-L/usr/local/include -lcunit

check_PROGRAMS=unit_hello
unit_hello_SOURCES=unit_hello.c ${top_srcdir}/src/hello/hello.c

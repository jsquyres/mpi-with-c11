lib_LTLIBRARIES = libmpi.la

libmpi_la_CPPFLAGS = -DBUILDING_LIBMPI=1
libmpi_la_SOURCES = \
        mpi.h \
        send_c.c \
        send_cxx.cc

bin_PROGRAMS = test_c test_cxx

test_c_SOURCES = test_c.c
test_c_LDADD = libmpi.la

test_cxx_SOURCES = test_cxx.cc
test_cxx_LDADD = libmpi.la

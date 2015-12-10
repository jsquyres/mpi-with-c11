lib_LTLIBRARIES = libmpi.la

libmpi_la_CPPFLAGS = -DBUILDING_LIBMPI=1
libmpi_la_SOURCES = \
        mpi.h \
        send.c

bin_PROGRAMS = test_mpi_send test_cxx

test_mpi_send_SOURCES = test_mpi_send.c
test_mpi_send_LDADD = libmpi.la

test_cxx_SOURCES = test_cxx.cc
test_cxx_LDADD = libmpi.la

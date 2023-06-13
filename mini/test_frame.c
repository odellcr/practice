/*
 * Two arrays nums1 and nums2, sorted ascending. Two integers m and n. Array nums1 has m elements
 * and is m + n size, nums2 has n elements and is n size. Merge nums1 and nums2 into nums1 in ascending order.
 *
 * Don't pass back rather store in nums1 which will be passed by reference. Only first m elements of nums1 are populated. 
 *
 *
 * Notes: Special cases, make sure to check for the instances where m or n are zero in which ther is no actual work to do. As well as m or n being.
 * */
#include <stdio.h>
#include <stdlib.h>
#include "munit.h"

// My function

// Test functions pre is called before test and post after
MunitResult test(const MunitParameter params[], void *data);
static void *pre(const MunitParameter params[], void* user_data);
static void post(void *fixture);

// Params maybe use to pass in test selects? don't need for my purposes
static char* foo_params[] = {
  "one", "two", "three", NULL
};

static char* bar_params[] = {
  "blue", "red", NULL
};

// Params array
static MunitParameterEnum test_params[] = {
  {"foo", foo_params},
  {"bar", bar_params},
  {NULL, NULL},
};

// Tests array. We are likely only using one
MunitTest tests[] = {
  { 
	"/my-test",
	test,
	pre,
	post,
	MUNIT_TEST_OPTION_NONE,
	test_params
  },
  {NULL,NULL,NULL,NULL,MUNIT_TEST_OPTION_NONE,NULL}
};

// Suite array again only using one
static const MunitSuite suite = {
  "/my-tests",
  tests,
  NULL,
  1,
  MUNIT_TEST_OPTION_NONE
};

// Calls the actual tests
int main(int argc, char *argv[])
{
  printf("Hello debug\n");

  return munit_suite_main(&suite, NULL, argc, argv);
}


static void *pre(const MunitParameter params[], void* user_data)
{
  int *a;

  a	= (int*)malloc(sizeof(int) * 1);

  a[0] = 1;

  return a;
}

static void post(void *fixture)
{
  //free(fixtrue);
}


// Actual test code, each test should do one thing i.e. one per test case, we just need multiples of these
MunitResult test(const MunitParameter params[], void *data)
{
  const char *foo;
  const char *bar;
  ret_val = MUNIT_ERROR;
  int t1[5] = {1,2,4,0,0};
  int t1_d[5] = {1,2,2,3,4};
  int t2[2] = {2,3};

  int *str = (int*) data;

  // Setup anything
  printf("here\n");

  // Call function we are testing
  
  // Do assert test here

  // Fill return value with result
  ret_val = MUNIT_OK;

  return ret_val;
}

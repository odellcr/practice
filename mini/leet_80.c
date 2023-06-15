/*
 *
 * Given an int array nums in acending order, remove some duplicates in-place such taht each unique element
 * appears at most twice. The relative order should be kept the same.
 *
 * Since it isn't possible to change the arrary length in some languages, you must instead have the result be placed in the first part of the array nums.
 *
 * If there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It doesn't matter what is byond the first k elements.
 *
 * Do not allocate extra space for another array (fixed space)
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "munit.h"

#define SZ(a) (sizeof(a) / sizeof((a)[0]))

// My function
int removeDuplicates(int *nums, int numsSize);

int removeDuplicates(int *nums, int numsSize)
{
  int i =0;
  int j= 0;
  int insert = 0;
  int valid = 0;
  int e = 0;
  int dup = 0;
  int k =0;
  int cache = 0;

  if(numsSize <= 1) {
	return numsSize;
  }
  if(nums == NULL) {
	return 0;
  }

  e = numsSize - 1;

  cache = nums[0];
  for(i = 0; i < e; i++) {
	if(cache == nums[i + 1]) {
	  if(dup) {
		nums[i + 1] = -1;
	  }
	  dup = 1;
	}
	else {
	  cache = nums[i + 1];
	  dup = 0;
	}
  }

  e = e + 1;
  for(i = 0; i < e; i++) {
	if(nums[i] == -1) {
	  if(j == 0) {
		j = i;
	  }
	  while(j < e && nums[j] == -1) {
		j++;
	  }
	  if(j < e) {
		cache = j;
		nums[i] = nums[j];
		nums[j] = -1;
	  }
	  // j means we have value
	  // e case we are done
	}

  }

  k = 0;
  for(k = 0; k < e && nums[k] != -1; k++);

  return k;

}

// Test functions pre is called before test and post after
MunitResult test_1(const MunitParameter params[], void *data);
MunitResult test_2(const MunitParameter params[], void *data);
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
	test_1,
	NULL, // pre
	NULL, // post
	MUNIT_TEST_OPTION_NONE,
	NULL
  },
  { 
	"/my-test",
	test_2,
	NULL, // pre
	NULL, // post
	MUNIT_TEST_OPTION_NONE,
	NULL
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
MunitResult test_1(const MunitParameter params[], void *data)
{
  int ret_val = MUNIT_ERROR;
  int n1[] = {0,0,1,1,1,1,2,3,3,};
  int n1_d[] = {0,0,1,1,2,3,3,-1,-1,-1};
  int n1_k = 7;
  int val = 3;
  int k;

  int *str = (int*) data;

  // Setup anything
  printf("T1\n");

  // Call function we are testing
  k = removeDuplicates(n1, sizeof(n1)/sizeof(n1[0]));

  for(int i = 0; i < k; i++)
  {
	printf("n1:%d\n", n1[i]);
  }
  
  for(int i = 0; i < n1_k; i++)
  {
	printf("n1_d:%d\n", n1_d[i]);
  }

  // Do assert test here
  munit_assert_memory_equal(sizeof(int) * n1_k, n1, n1_d);
  munit_assert(n1_k == k);

  // Fill return value with result
  ret_val = MUNIT_OK;

  return ret_val;
}

MunitResult test_2(const MunitParameter params[], void *data)
{
  int ret_val = MUNIT_ERROR;
  int n1[] = {1,1,1,2,2,3};
  int n1_d[] = {1,1,2,2,3,-1};
  int n1_k = 5;
  int val = 2;
  int k;

  int *str = (int*) data;

  // Setup anything
  printf("T2\n");

  // Call function we are testing
  k = removeDuplicates(n1, sizeof(n1)/sizeof(n1[0]));

  for(int i = 0; i < k; i++)
  {
	printf("n1:%d\n", n1[i]);
  }
  
  for(int i = 0; i < n1_k; i++)
  {
	printf("n1_d:%d\n", n1_d[i]);
  }

  // Do assert test here
  munit_assert_memory_equal(sizeof(int) * n1_k, n1, n1_d);
  munit_assert(n1_k == k);
 

  // Fill return value with result
  ret_val = MUNIT_OK;

  return ret_val;
}

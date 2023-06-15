/*
 * Given integer array nums and integer val, remove all occurrences of val in nums in-place. Order can be changed. Return the number of elements in nums which are not equal to val.
 *
 * Elements in nums which are NOT equal to val is k.
 *
 * Change nums such that the first k elements of nums contain the elements NOT equal to val.
 *
 * return k.
 */
#include <stdio.h>
#include <stdlib.h>
#include "munit.h"

#define SZ(a) (sizeof(a) / sizeof((a)[0]))

// My function
int removeElement(int *nums, int numsSize, int val);

int removeElement(int *nums, int numsSize, int val)
{
  int i;
  int j;
  int count = 0;

  if(numsSize == 0)
  {
	return 0;
  }

  printf("size is: %d\n", numsSize);
  for(i = 0; i < numsSize; i++)
  {
	if(nums[i] == val)
	{
	  j = i;

	  while(j != numsSize - 1 && nums[i] == val)
	  {
		for(j = i; j < numsSize - 1; j++)
		{
		  nums[j] = nums[j + 1];
		}

		nums[j] = val;

		for(j=i; j < numsSize - 1; j++)
		{
		  if(nums[j] != val)
		  {
			j = i;
			break;
		  }
		}
	  }
	}

	if(nums[i] != val)
	{
	  printf("%d\n",nums[i]);
	  count++;
	}
  }

  return count;
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
MunitResult test_2(const MunitParameter params[], void *data)
{
  int ret_val = MUNIT_ERROR;
  int n1[] = {3,2,2,3};
  int n1_d[] = {2,2,0,0};
  int n1_k = 2;
  int val = 3;
  int k;

  int *str = (int*) data;

  // Setup anything
  printf("T1\n");

  // Call function we are testing
  k = removeElement(n1, SZ(n1), val);

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

MunitResult test_1(const MunitParameter params[], void *data)
{
  int ret_val = MUNIT_ERROR;
  int n1[] = {0,1,2,2,3,0,4,2};
  int n1_d[] = {0,1,3,0,4,0,0,0};
  int n1_k = 5;
  int val = 2;
  int k;

  int *str = (int*) data;

  // Setup anything
  printf("T2\n");

  // Call function we are testing
  k = removeElement(n1, SZ(n1), val);

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

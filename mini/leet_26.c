/*
 * Given an int array 'nums' sorted in acending order, remove the duplicates in-place so that each unique element appears only once. The order of elements should be kept the same. Return number of unique elements in 'nums'.
 *
 * unique elements is k.
 *
 * array 'nums' first k elements need to contain the unique elements in the order they were present in nums.
 *
 * the remaining elements are irrelevant
 * return k
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "munit.h"

// My function
int removeDuplicates(int *nums, int numsSize);

int removeDuplicates(int *nums, int numsSize)
{
   int k = 0;
   int n = numsSize;
   int swp = 0;
   int i = 0;
   int j = 0;
   int count = 0;

   // all we need to do is detect it is a duplicate, count how many occurances, then shift that 
   // memory down
   for(i = 0; i < n - 1; i++)
   {
	 if(nums[i] == nums[i + 1])
	 {
	   swp = nums[i];
	   for(j = i; j < n - 1 && nums[j] == nums[j+1]; j++)
	   {
		 count++;
	   }
	   
	   for(j = i; j < n - 1 && count > 0; j++)
	   {
		 nums[j] = nums[j + 1];

		 if(j == n - 2)
		 {
		   count--;
		   nums[j + 1] = 0;
		   j = i;
		 }
	   }
	 }
   }

   for(i = 0; i < n - 1; i++)
   {
	 if(nums[i] < nums[i + 1])
	 {
	   k++;
	 }
	 else
	 {
	   break;
	 }
   }
   if(nums[i] != nums[i - 1])
   {
	 k++;
   }
   // loop over nums
   // if n = n + 1
   // 	loop over nums[i] until n != n + 1
   // 		count
   // 	for nums[i] < end && k = count--
   // 		nums[i] = nums[i + 1]
   // 		if(i = end - 1)
   // 			count --
   //
   // 	for that count perform the action n = n + 1 and do that n times
   // 	(some where you can optimize for count + i equal the end)
   // else n != n + 1 && n < n + 1 (need to protect against the fact we are moving to back
   // 	uid++ 
   

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
	pre,
	post,
	MUNIT_TEST_OPTION_NONE,
	test_params
  },
  { 
	"/my-test",
	test_2,
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
MunitResult test_1(const MunitParameter params[], void *data)
{
  int ret_val = MUNIT_ERROR;
  int nums[] = {1,1};
  int nums_d[] = {1,0};
  int k = 0;
  int n_k = 1;

  // Setup anything
  printf("here\n");

  // Call function we are testing
  k = removeDuplicates(nums, sizeof(nums)/sizeof(nums[0]));

  // Do assert test here
  munit_assert(k == n_k);
  munit_assert_memory_equal(k*sizeof(nums[0]), nums, nums_d);

  // Fill return value with result
  ret_val = MUNIT_OK;

  return ret_val;
}

MunitResult test_2(const MunitParameter params[], void *data)
{
  int ret_val = MUNIT_ERROR;
  int nums[] = {0,0,1,1,1,2,2,3,3,4};
  int nums_d[] = {0,1,2,3,4,0,0,0,0,0};
  int k = 0;
  int n_k = 5;

  // Setup anything
  printf("here\n");

  // Call function we are testing
  k = removeDuplicates(nums, sizeof(nums)/sizeof(nums[0]));

  // Do assert test here
  munit_assert(k == n_k);
  munit_assert_memory_equal(k*sizeof(nums[0]), nums, nums_d);

  // Fill return value with result
  ret_val = MUNIT_OK;

  return ret_val;
}

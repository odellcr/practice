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

void merge(int *nums1, int nums1Size, int m, int*nums2, int nums2Size, int n);
MunitResult my_test(const MunitParameter params[], void *user_data_or_fixture);

static char* foo_params[] = {
  "one", "two", "three", NULL
};

static char* bar_params[] = {
  "blue", "red", NULL
};

static MunitParameterEnum test_params[] = {
  {"foo", foo_params},
  {"bar", bar_params},
  {NULL, NULL},
};

static void *d(const MunitParameter params[], void* user_data)
{
  int *a;
	
  a	= (int*)malloc(sizeof(int) * 1);

  a[0] = 1;

  return a;
}

static void b(void *fixture)
{
  //free(fixtrue);
}

MunitTest tests[] = {
  { 
	"/my-test",
	my_test,
	d,
	b,
	MUNIT_TEST_OPTION_NONE,
	test_params
  },
  {NULL,NULL,NULL,NULL,MUNIT_TEST_OPTION_NONE,NULL}
};



static const MunitSuite suite = {
  "/my-tests",
  tests,
  NULL,
  1,
  MUNIT_TEST_OPTION_NONE
};


MunitResult my_test(const MunitParameter params[], void *user_data_or_fixture)
{
  const char *foo;
  const char *bar;
  int t1[5] = {1,2,4,0,0};
  int t1_d[5] = {1,2,2,3,4};
  int t2[2] = {2,3};

  int *str = (int*) user_data_or_fixture;

  merge(t1, 5, 3, t2, 2, 2);

  munit_assert_memory_equal(sizeof(int)*5, t1,t1_d); 
/*
  (void) user_data_or_fixture;

  foo = munit_parameters_get(params, "foo");
  bar = munit_parameters_get(params, "bar");

  printf("%s\n", foo);
*/
  return MUNIT_OK;
}


int main(int argc, char *argv[])
{
  return munit_suite_main(&suite, NULL, argc, argv);
}


void merge(int *nums1, int nums1Size, int m, int*nums2, int nums2Size, int n)
{
  int i = 0;
  int j1 = m - 1;
  int j2 = n - 1;
  int k = m + n - 1;

  if(n == 0)
	return;

  for(i = k; i >= 0; i--)
  {
	if(m != 0 && j1 >= 0 && (nums1[j1] > nums2[j2] || j2 < 0))
	{
	  nums1[i] = nums1[j1--];
	}
	else
	{
	  nums1[i] = nums2[j2--];
	}
  }
}

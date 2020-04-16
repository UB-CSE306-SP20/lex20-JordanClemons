#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "CUnit.h"
#include "Basic.h"
#include "counts.h"

void runFileTest(char * filename, char * target, int expected) {
  int actual = countWord(filename, target);
  CU_ASSERT_EQUAL(expected,actual);
}

void test_01(void) { runFileTest("../data/file01", "therefore", 2); }
void test_02(void) { runFileTest("../data/file01", "the", 0); }
void test_03(void) { runFileTest("../data/file02", "therefore", 1); }
void test_04(void) { runFileTest("../data/file02", "the", 2); }
void test_05(void) { runFileTest("../data/file03", "the", 13); }
void test_06(void) { runFileTest("../data/file03", "are", 2); }
void test_07(void) { runFileTest("../data/file03", "grippe", 1); }
void test_08(void) { runFileTest("../data/file03", "as", 3); }
void test_09(void) { runFileTest("../data/file03", "was", 3); }

int init_suite1(void) { return 0; }    /* The suite initialization function. */
int clean_suite1(void) { return 0; }   /* The suite cleanup function. */

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry()) { return CU_get_error(); }

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if (
          (NULL == CU_add_test(pSuite, "file01:therefore", test_01))
       || (NULL == CU_add_test(pSuite, "file01:the", test_02))
       || (NULL == CU_add_test(pSuite, "file02:therefore", test_03))
       || (NULL == CU_add_test(pSuite, "file02:the", test_04))
       || (NULL == CU_add_test(pSuite, "file03:the", test_05))
       || (NULL == CU_add_test(pSuite, "file03:are", test_06))
       || (NULL == CU_add_test(pSuite, "file03:grippe", test_07))
       || (NULL == CU_add_test(pSuite, "file03:as", test_08))
       || (NULL == CU_add_test(pSuite, "file03:was", test_09))
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}

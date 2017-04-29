#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include <string>
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "quick_sort.h"

using std::string;
using std::vector;
using std::ostream;
using std::cout;
using std::cin;
using std::setw;


struct TestSort {
    string name;
    void (*sortimp)(vector<int>& ary, int b, int e);
};
struct TestSelect {
    string name;
    int (*selectimp)(vector<int>& ary, int b, int e, int k);
};
void test_sort(ostream& out, const vector<vector<int>>& dataset, const vector<TestSort>& sortTests);
void test_select(ostream& out, const vector<vector<int>>& dataset, const vector<TestSelect>& selectTests);
vector<vector<int>> prepare_dataset();


int main()
{
    vector<vector<int>> dataset = prepare_dataset();

    test_sort(cout, dataset, {
        { "bubble sort", bubble_sort },
        { "insertion sort", insertion_sort },
        { "selection sort", selection_sort },
        { "merge sort", merge_sort },
        { "heap sort", heap_sort },
        { "quick sort", quick_sort },
    });

    test_select(cout, dataset, {
        { "quick select", quick_select }
    });

    cin.ignore();
    return 0;
}

void test_sort(ostream& out, const vector<vector<int>>& dataset, const vector<TestSort>& sortTests)
{
    for (auto testee : sortTests) {
        out << testee.name << "\n";

        int fail_c = 0;
        int test_c = 0;
        for (const vector<int>& data : dataset)
        {
            auto expected_data = data;
            sort(expected_data.begin(), expected_data.end());

            auto actual_data = data;
            testee.sortimp(actual_data, 0, int(actual_data.size()));

            test_c++;
            if (expected_data != actual_data)
            {
                fail_c++;
                out << "\nFailed!!\n";

                out << "origin: ";
                for (auto n : data) { out << setw(2) << n << " "; }
                out << "\n";

                out << "actual: ";
                for (auto n : actual_data) { out << setw(2) << n << " "; }
                out << "\n";

                out << "\n";
                break;
            }
            else
            {
                out << ".";
            }
        }
        out << "\n";

        if (fail_c == 0)
            out << "pass in " << test_c << " cases\n";
        else
            out << "fail rate: " << fail_c << "/" << test_c << "\n";
    }
}

void test_select(ostream& out, const vector<vector<int>>& dataset, const vector<TestSelect>& selectTests)
{
    for (auto testee : selectTests) {
        out << testee.name << "\n";

        int fail_c = 0;
        int test_c = 0;
        for (auto data : dataset) { // get fresh copy
            for (int k = 0; k < (int)data.size(); k++) {
                auto data_ith_expect = data;
                nth_element(data_ith_expect.begin(), data_ith_expect.begin() + k, data_ith_expect.end());
                auto kth_element_expect = data_ith_expect[k];

                auto data_ith_actual = data;
                auto p = testee.selectimp(data_ith_actual, 0, (int)data_ith_actual.size(), k);
                auto kth_element_actual = data_ith_actual[p];

                test_c++;
                if (kth_element_expect != kth_element_actual) {
                    fail_c++;
                    out << "origin: ";
                    for (auto n : data) { out << setw(2) << n << " "; }
                    out << "\n";
                    out << "k: " << k << "\n";
                    out << "expect: " << kth_element_expect << "\n";
                    out << "actual: " << kth_element_actual << "\n";
                    out << "\n";

                    out << "\n";
                }
                else {
                    out << ".";
                }
            }
        }
        out << "\n";
        if (fail_c == 0)
            out << "pass in " << test_c << " cases\n";
        else
            out << "fail rate: " << fail_c << "/" << test_c << "\n";
    }
}

vector<vector<int>> prepare_dataset()
{
    vector<vector<int>> dataset;

    srand(0);
    dataset.push_back({});
    dataset.push_back({ 0 });
    dataset.push_back({ 1,2 });
    dataset.push_back({ 1,1 });
    dataset.push_back({ 3,2,3,1,2,3,4,3,2,1 });
    dataset.push_back({ 1,2,3,4,5 });
    dataset.push_back({ 5,4,3,2,1 });

    for (int i = 0; i < 5; i++) { // random in [0,10)
        vector<int> data;
        generate_n(back_inserter(data), 20, [] {return rand() % 10; });
        dataset.push_back(data);
    }

    for (int i = 0; i < 5; i++) { // random in [0, 1000)
        vector<int> data;
        generate_n(back_inserter(data), 20, [] {return rand() % 1000; });
        dataset.push_back(data);
    }

    {// sorted
        vector<int> data;
        generate_n(back_inserter(data), 100, [] {return rand() % 100; });
        sort(data.begin(), data.end());
        dataset.push_back(data);
    }
    { // reversed
        vector<int> data;
        generate_n(back_inserter(data), 100, [] {return rand() % 100; });
        sort(data.begin(), data.end(), [](int lhs, int rhs) { return lhs > rhs; });
        dataset.push_back(data);
    }
    return dataset;
}
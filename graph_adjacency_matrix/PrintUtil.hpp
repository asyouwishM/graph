#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>
#include"ListNode.hpp"
using namespace std;
class PrintUtil
{
public:
    //find an element in a vector
    template <typename T>
    static int vecFind(const vector<T>& vec, T ele)
    {
        int j = INT_MAX;
        for (int i = 0; i < vec.size(); i++)
        {
            if(vec[i]==ele)
            {
                j = i;
            }
        }
        return j;
    }
    //concatenare a vector with a delim
    template <typename T>
    static string strJoin(const string &delim, const T &vec)
    {
        ostringstream s;
        for (const auto &i : vec)
        {
            if (&i != &vec[0])
            {
                s << delim;
            }
            s << i;
        }
        return s.str();
    }
    //repeat a string for n times
    template <typename T>
    static string strRepeat(string str, int n)
    {
        ostringstream os;
        for (int i = 0; i < n;i++)
            os << str;
        return os.str();
    }
    //print an array
    template<typename T>
    static void printArray(T* arr, int n)
    {
        cout << "[";
        for (int i = 0; i < n - 1;i++)
        {
            cout << arr[i] << ", ";
        }
        if(n>=1)
            cout << arr[n - 1] << "]" << endl;
    }
    //get the string object
    template<typename T>
    static string getVectorString(vector<T> &list)
    {
        return "[" + strJoin(", ", list) + "]";
    }
    //print a vector
    template <typename T>
    static void printVector(vector<T> list)
    {
        cout << getVectorString(list) << '\n';
    }
    //print a vector matrix
    template<typename T>
    static void printVectorMatrix(vector<vector<T>> &matrix)
    {
        cout << "[" << '\n';
        for(vector<T> &list : matrix)
            cout << " " + getVectorString(list) + "," << '\n';
        cout << "]" << '\n';
    }
    //print a linked list
    // template<typename T>
    // static void printLinkList(ListNode *head)
    // {
    //     vector<int> list;
    //     while(head !=nullptr)
    //     {
    //         list.push_back(head->val);
    //         head = head->next;
    //     }
    //     cout << strJoin("->", list) << '\n';
    // }

};
    
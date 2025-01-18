/*
Problem Statement: Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. 
There are a ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:

Each student gets at least one book.
Each book should be allocated to only one student.
Book allocation should be in a contiguous manner.
You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. 
If the allocation of books is not possible. return -1
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int sumArr(vector<int> arr) {
    int sum=0;
    for(int i=0; i<arr.size(); i++) sum+=arr[i];
    return sum;
}
int numOfStudents(vector<int>& books, int minPages) {
    // this func returns for given num of min pages, how many students would be there
    int student=1, currentPages=0; // currently we're at student 1 and she has 0 pages

    for(int i=0; i<books.size(); i++) {
        if(currentPages+books[i]<=minPages) {
            currentPages += books[i]; // if student can hold book[i], add pages to currentPages
        } else{
            student++;
            currentPages=books[i]; // otherwise move to next student and reset currentPages to 0.
        }
    }
    return student;
}
int minOfMaxPages(vector<int> &books, int students) {
    // takes input of books array and number of students the book must be divided to that each have atleast a book
    if(books.size()<students) return -1;
    if(books.size()==students) return *max_element(books.begin(), books.end());

    int low=*max_element(books.begin(), books.end()); //lowest amt of page a student can have
    int high=sumArr(books); //highest being she has all books
    int ans=-1, mid;

    //if for x min num of pages we have more than req students, we would need to inc min num of pages
    //if for x min num of pages we have exactly the num of req students, we'll look for a greater num to see if conditions are satisfied
    //if for x min num of pages we have less than req students, we need to dec req num of students

    while(low<=high) {
        mid = low+(high-low)/2;
        int s = numOfStudents(books, mid);
        if(s <= students) {  // Check for <= students instead of == 
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int main() {
    vector<int> books = {12, 34, 67, 90};
    int n = 4;
    cout << minOfMaxPages(books, n);

    return 0;
}
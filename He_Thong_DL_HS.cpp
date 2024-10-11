#include <iostream>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

void gotoxy(int x, int y) //ham dua con tro toi vi tri (x,y)
{
    static HANDLE h = NULL;  
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };  
    SetConsoleCursorPosition(h,c);
}

//Node Class
class Node {
    public:
        int roll;
        string ten;
        int toan, ly, hoa;
        int tong = 0;
        Node* next;
};

//Luu du lieu dau cua LinkedList
Node* head = new Node();

//Kiem tra Function du lieu da ton tai chua
bool check(int x) {
    //Truong hop dau
    if (head == NULL) return false;
    Node* t = new Node;
    t = head;
    //Truong hop con lai
    while (t != NULL) {
        if (t -> roll == x) return true;
        t = t -> next;
    }
    return false;
}

//Function them du lieu
void Insert_Record(int roll, string ten, int toan, int ly, int hoa, int tong) {
    //neu du lieu da ton tai
    if (check(roll)) {
        cout << "Hoc sinh nay da co san\n";
        cout << "An phim bat ky de quay lai Menu.";
        getch();
        system("cls");
        return;
    }
    //Tao node moi de them du lieu
    Node* t = new Node();
    t -> roll = roll;
    t -> ten = ten;
    t -> toan = toan;
    t -> ly = ly;
    t -> hoa = hoa;
    t -> tong = toan + ly + hoa;
    //Them vao dau
    if (head == NULL or (head -> roll >= t -> roll)) {
        t -> next = head;
        head = t;
    }
    //Them vao giua hoac cuoi
    else {
        Node* c = head;
        while (c -> next != NULL and c -> next -> roll < t -> roll) {
            c = c -> next;
        }
        t -> next = c -> next;
        c -> next = t;
    }
    cout << "Them du lieu thanh cong, an phim bat ky de quay lai.\n";
    getch();
    system("cls");
}

//Function tim du lieu hoc sinh bang so thu tu
void Search_Record(int roll) {
    //neu dau NULL
    if (!head) {
        cout << "Khong co du lieu\n";
    }
    else {
        Node* p = head;
        while (p) {
            if (p -> roll == roll) {
                gotoxy(2,1);
                cout << "STT";
                gotoxy(12,1);
                cout << "Ho va Ten";
                gotoxy(45,1);
                cout << "Toan";
                gotoxy(55,1);
                cout << "Ly";
                gotoxy(65,1);
                cout << "Hoa";
                gotoxy(75,1);
                cout << "Tong";
                gotoxy(2,2);
                cout << p -> roll;
                gotoxy(12,2);
                cout << p -> ten;
                gotoxy(45,2);
                cout << p -> toan;
                gotoxy(55,2);
                cout << p -> ly;
                gotoxy(65,2);
                cout << p -> hoa;
                gotoxy(75,2);
                cout << p -> tong << endl;
                break;
            }
            p = p -> next;
        }
        if (p == NULL) cout << "khong co du lieu\n";
    }
    cout << "\nAn phim bat ky de quay lai menu.";
    getch();
    system("cls");
}

//Xoa du lieu theo so thu tu neu co
int Delete_Record(int roll) { // please fix later thanks this is stupid
    Node* t = head;
    Node* p = NULL;
    //Xoa o dau
    if (t != NULL and t -> roll == roll) {
        head = t -> next;
        delete t;
        cout << "Xoa du lieu thanh cong\n";
    }
    //Xoa o vi tri khac
    while (t != NULL and t -> roll != roll) {
        p = t;
        t = t -> next;
    }
    if (t == NULL) { // ??? this entire part does not make sense
        cout << "Du lieu khong ton tai.\n";
        p -> next = t -> next;

        delete t;
        cout << "Xoa du lieu thanh cong\n";
    }
    cout << "\nAn phim bat ky de quay lai menu.";
    getch();
    system("cls");
}

//Function liet ke danh sach hoc sinh
void Show_Record() {
    system("cls");
    Node* p = head;
    if (p == NULL) {
        cout << "khong co du lieu\n";
    }
    else {
        gotoxy(2,1);
        cout << "STT";
        gotoxy(12,1);
        cout << "Ho va Ten";
        gotoxy(45,1);
        cout << "Toan";
        gotoxy(55,1);
        cout << "Ly";
        gotoxy(65,1);
        cout << "Hoa";
        gotoxy(75,1);
        cout << "Tong";
        //cho toi khi p khong phai la NULL
        while (p != NULL) {
            int i = p -> roll;
            gotoxy(2,i+1);
            cout << p -> roll;
            gotoxy(12,i+1);
            cout << p -> ten;
            gotoxy(45,i+1);
            cout << p -> toan;
            gotoxy(55,i+1);
            cout << p -> ly;
            gotoxy(65,i+1);
            cout << p -> hoa;
            gotoxy(75,i+1);
            cout << p -> tong << endl;
            p = p -> next;
        }
    }
    cout << "\nAn phim bat ky de ve Menu.";
    getch();
    system("cls");
}

int main() {
    head = NULL;
    string ten;
    int roll, toan, ly, hoa, tong;
    
    //He thong Menu
    while (true) {
        cout << "\n\t\tHe Thong Du Lieu Hoc Sinh "
                "\n\n\tAn"
                "\n\t1: Tao Du Lieu moi"
                "\n\t2: Xoa Du Lieu"
                "\n\t3: Truy Tim Du Lieu Hoc Sinh"
                "\n\t4: Liet ke Danh Sach Day Du"
                "\n\t5: Thoat He Thong\n";
        cout << "\nEnter your Choice: ";
        int Choice;
        //nhap Lua chon
        cin >> Choice;
        switch(Choice) {
            case 1:
                system("cls");
                cout << "Nhap STT: ";
                cin >> roll;
                cout << "Nhap Ho va Ten: ";
                cin >> ten;
                cout << "Nhap Diem Toan: ";
                cin >> toan;
                cout << "Nhap Diem Ly: ";
                cin >> ly;
                cout << "Nhap Diem Hoa: ";
                cin >> hoa;
                Insert_Record(roll,ten,toan,ly,hoa,tong);
                break;
            case 2:
                system("cls");
                cout << "Nhap STT can xoa DL: ";
                cin >> roll;
                Delete_Record(roll);
                break;
            case 3:
                system("cls");
                cout << "Nhap STT can tra cuu: ";
                cin >> roll;
                Search_Record(roll);
                break;
            case 4:
                system("cls");
                Show_Record();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout << "invalid input! Press any key to return";
                getch();
                system("cls");
                break;
        }
    }
    return 0;
    // test
}

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

class Node {
public:
    string mave;
    string bsxe;
    string loaixe;
    string ngaybatdau;
    string tennguoimua;
    int giave;
    Node* next;

    Node(string mave, string bsxe, string loaixe, string ngaybatdau, string tennguoimua, int giave)
        : mave(mave), bsxe(bsxe), loaixe(loaixe), ngaybatdau(ngaybatdau), tennguoimua(tennguoimua), giave(giave), next(nullptr) {}
};

class DanhSachLienKet {
private:
    Node* head;
    Node* last;

public:
    DanhSachLienKet() : head(nullptr), last(nullptr) {}

    void khoiTao() {
        head = last = nullptr;
    }

    Node* taoNode(string mave, string bsxe, string loaixe, string ngaybatdau, string tennguoimua, int giave) {
        return new Node(mave, bsxe, loaixe, ngaybatdau, tennguoimua, giave);
    }

    void locGiaVeLonHon(int giave) {
        for (Node* m1 = head; m1 != nullptr; m1 = m1->next) {
            if (m1->giave > giave) {
                cout << m1->mave << " " << m1->giave << endl;
            }
        }
        cout << endl;
    }

    Node* layNode(string mave) {
        for (Node* m1 = head; m1 != nullptr; m1 = m1->next) {
            if (m1->mave == mave) {
                return m1;
            }
        }
        return nullptr;
    }

    void capNhatThongTin() {
        string mave, biensoxe, loaixe, ngaybatdau, nguoimua;
        int giave;
        cout << "Nhap ma ve: ";
        cin >> mave;

        Node* node = layNode(mave);
        if (node) {
           cout << "Nhap bien so xe: ";
           cin >> biensoxe;
        
           // Xóa bộ đệm đầu vào trước khi sử dụng getline
           cin.ignore(numeric_limits<streamsize>::max(), '\n');

           cout << "Nhap loai xe: ";
           getline(cin, loaixe);
        
           cout << "Nhap ngay bat dau khoi hanh (dd/mm/yyyy): ";
           getline(cin, ngaybatdau);
        
           cout << "Nhap ten nguoi mua: ";
           getline(cin, nguoimua);
        
           cout << "Nhap gia ve: ";
           cin >> giave;

           node->bsxe = biensoxe;
           node->loaixe = loaixe;
           node->ngaybatdau = ngaybatdau;
           node->tennguoimua = nguoimua;
           node->giave = giave;
        } else {
           cout << "Khong tim thay ma ve!" << endl;
        }
    }

    void themCuoi(string mave, string bsxe, string loaixe, string ngaybatdau, string tennguoimua, int giave) {
        Node* temp = taoNode(mave, bsxe, loaixe, ngaybatdau, tennguoimua, giave);
        if (last == nullptr) {
            head = last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }

    void nhapThongTin() {
        string mave, biensoxe, loaixe, ngaybatdau, nguoimua;
        int giave;
        cout << "Nhap ma ve: ";
        cin >> mave;
        cout << "Nhap bien so xe: ";
        cin >> biensoxe;
    
        // Xóa bộ đệm đầu vào trước khi sử dụng getline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
        cout << "Nhap loai xe: ";
        getline(cin, loaixe);
    
        cout << "Nhap ngay bat dau khoi hanh (dd/mm/yyyy): ";
        getline(cin, ngaybatdau);
    
        cout << "Nhap ten nguoi mua: ";
        getline(cin, nguoimua);
    
        cout << "Nhap gia ve: ";
        cin >> giave;

        themCuoi(mave, biensoxe, loaixe, ngaybatdau, nguoimua, giave);
        
    }

    void xoaNode(string mave) {
        if (head == nullptr) return;

        if (head->mave == mave) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                last = nullptr;
            }
            return;
        }

        Node* prev = head;
        Node* curr = head->next;
        while (curr != nullptr && curr->mave != mave) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Khong tim thay ma ve!" << endl;
            return;
        }

        prev->next = curr->next;
        if (curr == last) {
            last = prev;
        }
        delete curr;
    }

    bool danhSachRong() {
        return head == nullptr;
    }

    string tachThang(string ngaybatdau) {
        string thang;
        int firstSlash = ngaybatdau.find('/');
        int secondSlash = ngaybatdau.find('/', firstSlash + 1);
        if (firstSlash != string::npos && secondSlash != string::npos) {
            thang = ngaybatdau.substr(firstSlash + 1, secondSlash - firstSlash - 1);
        }
        return thang;
    }

    void layVeTheoThang(string thang) {
        for (Node* m1 = head; m1 != nullptr; m1 = m1->next) {
            if (tachThang(m1->ngaybatdau) == thang) {
                cout << m1->mave << " " << m1->tennguoimua << " " << m1->ngaybatdau << endl;
            }
        }
    }

    void hoanDoi(Node* m1, Node* m2) {
        swap(m1->mave, m2->mave);
        swap(m1->bsxe, m2->bsxe);
        swap(m1->loaixe, m2->loaixe);
        swap(m1->ngaybatdau, m2->ngaybatdau);
        swap(m1->tennguoimua, m2->tennguoimua);
        swap(m1->giave, m2->giave);
    }

    void sapXep() {
        for (Node* m1 = head; m1 != nullptr; m1 = m1->next) {
            for (Node* m2 = m1->next; m2 != nullptr; m2 = m2->next) {
                if (m2->giave > m1->giave) {
                    hoanDoi(m1, m2);
                }
            }
        }
    }

    void layVeTheoTenNguoiDung(string tennguoidung) {
        for (Node* m1 = head; m1 != nullptr; m1 = m1->next) {
            if (m1->tennguoimua == tennguoidung) {
                cout << m1->mave << " " << m1->tennguoimua << " " << m1->ngaybatdau << endl;
            }
        }
    }

    int tinhTongGiaVe() {
        int tong = 0;
        for (Node* m1 = head; m1 != nullptr; m1 = m1->next) {
            tong += m1->giave;
        }
        return tong;
    }

    void docTuFile(string filename) {
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;

            stringstream ss(line);
            string mave, biensoxe, loaixe, ngaybatdau, tennguoimua;
            string giave_str;
            int giave = 0;
            int dem = 0;

            while (getline(ss, giave_str, ',')) {
                dem++;
                if (dem == 1) mave = giave_str;
                else if (dem == 2) biensoxe = giave_str;
                else if (dem == 3) loaixe = giave_str;
                else if (dem == 4) ngaybatdau = giave_str;
                else if (dem == 5) tennguoimua = giave_str;
                else if (dem == 6) {
                    try {
                        giave = stoi(giave_str);
                    } catch (const std::invalid_argument& e) {
                        cerr << "Gia tri vuot qua pham vi: " << e.what() << " o dong: " << line << endl;
                     continue;
                    }
                }
            }
            themCuoi(mave, biensoxe, loaixe, ngaybatdau, tennguoimua, giave);
        }
    }
    void inDanhSach() {
        for (Node* m1 = head; m1 != nullptr; m1 = m1->next) {
            cout << m1->mave << " " << m1->bsxe << " " << m1->loaixe << " " << m1->ngaybatdau << " " << m1->tennguoimua << " " << m1->giave << endl;
        }
    }
};

int main() {
   DanhSachLienKet ds;
   int input;
   string mave, thang, tennguoidung;
   int giave;
   
   // Đọc dữ liệu từ file vexe.txt
   ds.docTuFile("vexe.txt");

   while (true) {
       cout << "CHUONG TRINH QUAN LY VE XE\n";
       cout << "CHUC NANG : \n";
       cout << "1. Them thong tin ve xe.\n";
       cout << "2. Sua thong tin ve xe.\n";
       cout << "3. Xoa thong tin ve xe.\n";
       cout << "4. Dua ra thong tin ve xe theo thang.\n";
       cout << "5. Sap xep ve xe theo gia ve.\n";
       cout << "6. Dua ra thong tin cac ve xe theo ten nguoi dung.\n";
       cout << "7. Tinh tong gia ve.\n";
       cout << "8. Loc cac ve co gia cao hon gia nhap tu ban phim.\n";
       cout << "9. Doc thong tin tu file.\n";
       cout << "0. Thoat.\n";
       cout << "Ban chon: ";
       cin >> input;

       switch (input) {
       case 1:
           ds.nhapThongTin();
           break;
       case 2:
           ds.capNhatThongTin();
           cout << "Danh sach sau khi cap nhat thong tin:" << endl;
           ds.inDanhSach();
       break;
       case 3:
           cout << "Nhap ma ve can xoa: ";
           cin >> mave;
           ds.xoaNode(mave);
           cout << "Danh sach sau khi xoa:" << endl;
           ds.inDanhSach();
       break;
       case 4:
           cout << "Nhap thang can tim: ";
           cin >> thang;
           ds.layVeTheoThang(thang);
       break;
       case 5:
           ds.sapXep();
           cout << "Danh sach sau khi sap xep:" << endl;
           ds.inDanhSach();
       break;
       case 6:
           cin.ignore();
           cout << "Nhap ten nguoi dung: ";
           getline(cin, tennguoidung);
           cout << "Thong tin ve xe theo ten nguoi dung:" << endl;
           ds.layVeTheoTenNguoiDung(tennguoidung);
       break;
       case 7:
           cout << "Tong gia ve da ban la: " << ds.tinhTongGiaVe() << endl;
       break;
       case 8:
           cout << "Nhap gia ve: ";
           cin >> giave;
           cout << "Cac ve xe co menh gia cao hon la: ";
           ds.locGiaVeLonHon(giave);
       break;
       case 9:
           ds.docTuFile("vexe.txt");
           cout << "Danh sach ve xe sau khi doc tu file:" << endl;
           ds.inDanhSach();
       break;
       case 0:
           return 0;
       default:
           cout << "Lua chon khong hop le, vui long chon lai!" << endl;
           break;
        }
    }
}


#include <iostream>
#include <vector>
using namespace std;

class Shape {
protected:
    virtual void draw() = 0;
public:
    void paint() { draw(); }
};

class Circle : public Shape {
protected:
    virtual void draw() { cout << "Circle" << endl; }
};

class Rect : public Shape {
protected:
    virtual void draw() { cout << "Rectangle" << endl; }
};

class Line : public Shape {
protected:
    virtual void draw() { cout << "Line" << endl; }
};

class UI {
public:
    static int seleteMenu() {
        int n;
        cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
        cin >> n;
        return n;
    }
    static int seleteShape() {
        int n;
        cout << "선:1, 원:2, 사각형:3 >> ";
        cin >> n;
        return n;
    }
    static int seleteDelIndex() {
        int n;
        cout << "삭제하고자 하는 도형의 인덱스 >> ";
        cin >> n;
        return n;
    }
    static void showAll(vector<Shape*>& v, vector<Shape*>::iterator& it) {
        int i = 0;
        for (it = v.begin(); it != v.end(); it++, i++) {
            cout << i << ": ";
            v.at(i)->paint();
        }
    }
};

class GraphicEditor {
    vector<Shape*> v;
    vector<Shape*>::iterator it;
public:
    GraphicEditor() {
        cout << "그래픽 에디터입니다.\n";
        start();
    }
    void start() {
        while (true) {
            int n;
            n = UI::seleteMenu();
            switch (n) {
            case 1: //삽입
                n = UI::seleteShape();
                switch (n) {
                case 1: //선
                    v.push_back(new Line());
                    break;
                case 2: //원
                    v.push_back(new Circle());
                    break;
                case 3: //사각형
                    v.push_back(new Rect());
                    break;
                default:
                    cout << "잘못 선택하셨습니다.\n";
                    break;
                }
                break;
            case 2: { //삭제
                n = UI::seleteDelIndex();
                if (n >= v.size() || n < 0) { //예외처리  
                    cout << "없는 인덱스 입니다.\n";
                    break;
                }
                it = v.begin();
                Shape* tmp = *(it + n);
                v.erase(it + n); // it+n 원소 삭제
                delete tmp; 
                break;
            }
            case 3: //모두 보기
                UI::showAll(v, it);
                break;
            case 4: // 종료
                return; 
            default:
                cout << "잘못 입력하셨습니다.\n";
                break;
            }
        }
    }

};

int main() {
    new GraphicEditor();
}

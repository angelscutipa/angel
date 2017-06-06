#include <iostream>

using namespace std;

template<class T>
class nodo
{
public:
	T x, y;
	T dato;
	nodo<T>* right;
	nodo<T>* down;
	nodo(T,T,T);
	~nodo(){};
	
};

template<class T>
nodo<T>::nodo(T _x, T _y, T _dato){
	dato=_dato;
	x=_x;
	y=_y;
	right=down=NULL;
}



template <class T, T N>
class matrix
{
public:
	nodo<T>** m_hor, **m_ver;
	matrix(int x, int y);
	bool set(T x, T y, T dato);
	bool buscarx(T dato, nodo<T>**&p, T ind);
	bool buscary(T dato, nodo<T>**&p, T ind);
	void print();
	~matrix(){};

};

template <class T, T N>
matrix<T,N>::matrix(int x, int y){
	m_hor=new nodo<T>*[x];
	for (int i = 0; i < x; ++i)
	{
		m_hor[i]=NULL;
	}

	m_ver=new nodo<T>*[y];
	for (int i = 0; i < y; ++i)
	{
		m_ver[i]=NULL;
	}
}

template<class T, T N>
bool matrix<T,N>::set(T x, T y, T dato){
	nodo<T>** _x, **_y;
	if(this->buscarx(y,_x,x) || this->buscary(x,_y,y))return 0;
	nodo<T>* n=new nodo<T>(x,y, dato);
	n->down=(*_x);
	(*_x)=n;
	n->right=(*_y);
	(*_y)=n;
	return 1;
}

template<class T, T N>
bool matrix<T,N>::buscarx(T dato, nodo<T>**&p, T ind){
	p=&(m_hor[ind]);
	//cout<<"hola"<<endl;
	while ((*p) && dato!=(*p)->y){
		p = &((*p)->down);
	}

	if ((*p) && dato == (*p)->y) {
		return true;
	}
	return false;
}

template<class T, T N>
bool matrix<T,N>::buscary(T dato, nodo<T>**&p, T ind){
	p=&(m_ver[ind]);
	while ((*p) && dato!=(*p)->x) {
		p = &((*p)->right);
	}

	if ((*p) && dato == (*p)->x) {
		return true;
	}
	return false;
}

template<class T, T N>
void matrix<T,N>::print(){
	nodo<T>* temp;
	temp=m_ver[1];
	while(temp!=NULL){
		cout<<temp->dato<<endl;
		temp=temp->right;
	}
	nodo<T>* tem;
	for (int i = 0; i < 4; ++i)
	{
		
		tem=m_ver[i];
		for (int j = 0; j < 4; ++j)
		{
			if(tem!=NULL && j==tem->x && i==tem->y){
				cout<<tem->dato<<" ";
				tem=tem->right;
			}
			else{
				cout<<0<<" ";
			}
			
		}
		cout<<endl;
	}
}

template<class T>
T& operator [](const T &x, const T &y){
		nodo<T>** temp;
		buscarx(y,temp,x);
		return (*temp)->dato;
	}

int main(int argc, char const *argv[])
{
	matrix<int,0> m(4,4);
	cout<<"hola"<<endl;
	m.set(0,0,4);
	m.set(2,1,5);
	m.set(1,2,7);
	m.set(2,2,3);
	m.set(1,1,8);
	m.set(3,3,2);
	m.set(2,0,9);
	m.set(3,0,8);
	m.print();
	int a;
	a=m[3,3];
	cout<<a<<endl;
	return 0;
}
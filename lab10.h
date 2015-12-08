#pragma once 
#include <iostream>
#define METER 100
#define SECOND 1

class Type 
{
 	public :
		Type(float val ) : value (val ) {}
		float Get () {return value ;}
		
	private:
		float value ;

};


template < int T > 
class Float_t :public Type 
{
	public :

		Float_t ( float  ) ;
		float Get () ;
		Float_t <  T > operator + ( Float_t<T> & );
		template < int Y> 
		Float_t <T+Y > operator * (Float_t<Y> & );
		 template < int Y> 
		Float_t <T-Y > operator / (Float_t<Y> & );
		
		


	private :
		float  value ;


};
struct List
{
	Type * actual ;
	List * next;
};
class Array_t
{
	public :
		Array_t (int size):_size(size),head(NULL)
		{
		}
		void Add(Type * );
		void PrintAll();
		~Array_t();


		
	private :
		int _size ;
		List * head ;
		

		 


};
/***** Array_t *******************/
 void Array_t :: Add ( Type * object ) 
{
	List * toAdd = new List  ;
	toAdd -> actual = object ;
	toAdd ->next=NULL;
	if ( head!=NULL ) 
	{
		List * temp = head;
 
		while (  temp->next!=NULL) 
		{
			std::cout<<"JESTEM "<<std::endl;
			temp  = temp->next ;
			 
		}		
		temp->next = toAdd ;


	}
	else 
	{
		head= toAdd;

	}
	

}
void Array_t ::PrintAll ( ) 
{
	List * temp = head;
	while( temp)
	{
		std::cout <<temp->actual->Get()<<std::endl;
		temp=temp->next;
	}

}
 Array_t :: ~Array_t ()
{	
	List * temp = head;
	while ( temp )
	{
	temp=temp->next;
	delete head ;
	head = temp ;

	}
}
/****Float_t finctions*******************/
template <int T>
Float_t<T>::Float_t ( float val) :Type(val),value ( val ) 
{
	
}

template <int T>
float Float_t<T>::Get () 
{
	return value ;

}
template <int T > 
Float_t<T>  Float_t<T> :: operator + ( Float_t<T> & abc ) 
{
	return this->Get() + abc.Get();
};

template <int T > 
template < int Y> 
Float_t<T+Y>  Float_t<T> :: operator * ( Float_t<Y> & abc ) 
{
	return this->Get() * abc.Get();
};
template <int T > 
template < int Y> 
Float_t<T-Y>  Float_t<T> :: operator / ( Float_t<Y> & abc ) 
{
	return this->Get() / abc.Get();
};


#pragma once

template <class T>
class My_Shared_Ptr
{
	T* obj;
	static int amount;
public:
	My_Shared_Ptr() = default;

	My_Shared_Ptr(T* prev_obj) {
		obj = prev_obj;
		amount++;
	}

	My_Shared_Ptr(const My_Shared_Ptr<T>& prev_obj) {
		obj = prev_obj.obj;
		amount++;
	}

	void operator=(const T& prev_obj) {
		obj = prev_obj.obj;
		amount++;
	}

	int Get_amount() {
		return amount;
	}

	T* get() {
		return obj;
	}

	~My_Shared_Ptr() {
		if (amount == 1)
			delete obj;
		else
			amount--;
	}
};

template <class T>
int My_Shared_Ptr<T>::amount = 0;
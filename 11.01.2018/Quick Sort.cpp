
template<typename T>
void swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}

template<typename T>
unsigned partition(T* a, unsigned left, unsigned right) {

	T pivot = a[left + (right - left) / 2];
	swap(a[left], a[left + (right - left) / 2]);

	unsigned ind = left;

	for (unsigned i = left + 1; i < right; i++) {
		if (a[i] <= pivot) {
			ind++;
			swap(a[i], a[ind]);
		}
	}
	swap(a[left], a[ind]);
	return ind;
}

template<typename T>
void quick_sort(T* arr, unsigned left, unsigned right) {

	if (right - left <= 1) {
		return;
	}
	unsigned index = partition(arr, left, right);
	quick_sort(arr, left, index);
	quick_sort(arr, index + 1, right);
}

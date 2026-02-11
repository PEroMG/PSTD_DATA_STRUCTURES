#pragma once

#define _PSTD_DATA_STRUCTURE_

#include <type_traits>
#include <iterator>
#include <memory>


#if !defined(PSTD_DATA_STRUCTURE_NO_OSTREAM)
#include <ostream>
#endif // DEBUG


namespace PSTD {

	template <typename ty, size_t m_size>
	class array {
	public:
		ty internal_array[m_size];

	

		using value_type = ty;

		using size_type = size_t;
		using difference_type = std::ptrdiff_t;
		using reference = ty&;
		using const_reference = const ty&;
		using pointer = value_type*;
		using const_pointer = const value_type*;
		using const_pointer_reference = PSTD::array<ty, m_size>::const_pointer&;

		class iterator {
			ty* ptr = nullptr;

		public:

			using iterator_category = std::random_access_iterator_tag;
			using value_type = ty;
			using difference_type = std::ptrdiff_t;
			using pointer = ty*;
			using reference = ty&;

			iterator(const pointer& it_pointer) : ptr(it_pointer) {}

			reference operator*() const { return *ptr; }
			const_pointer operator->() const { return ptr; }

			PSTD::array<ty, m_size>::iterator& operator++() {
				ptr++;
				return *this;
			}
			PSTD::array<ty, m_size>::iterator operator++(int) {
				return PSTD::array<ty, m_size>::iterator(ptr++);
			}

			PSTD::array<ty, m_size>::iterator& operator--() {
				ptr--;
				return *this;
			}
			PSTD::array<ty, m_size>::iterator operator--(int) {
				return PSTD::array<ty, m_size>::iterator(ptr--);
			}

			bool operator == (const PSTD::array<ty, m_size>::iterator& other) const {
				return ptr == other.ptr;
			}
			bool operator != (const PSTD::array<ty, m_size>::iterator& other) const {
				return ptr != other.ptr;
			}
			bool operator <= (const PSTD::array<ty, m_size>::iterator& other) const {
				return ptr <= other.ptr;
			}
			bool operator >= (const PSTD::array<ty, m_size>::iterator& other) const {
				return ptr >= other.ptr;
			}
			bool operator < (const PSTD::array<ty, m_size>::iterator& other) const {
				return ptr < other.ptr;
			}
			bool operator > (const PSTD::array<ty, m_size>::iterator& other) const {
				return ptr > other.ptr;
			}

			PSTD::array<ty, m_size>::iterator operator+(const int& n) const {
				return PSTD::array<ty, m_size>::iterator(ptr + n);
			}
			PSTD::array<ty, m_size>::iterator operator-(const int& n) const {
				return PSTD::array<ty, m_size>::iterator(ptr - n);
			}

			PSTD::array<ty, m_size>::iterator& operator+= (const int& n) {
				ptr += n; return *this;
			}
			PSTD::array<ty, m_size>::iterator& operator-= (const int& n) {
				ptr -= n; return *this;
			}

			difference_type operator-(const PSTD::array<ty, m_size>::iterator& other) const {
				return ptr - other.ptr;
			}
			/*operator[]*/ty& operator[] (const int& n) const {
				return ptr[n];
			}
		};

		class const_iterator {
			const ty* ptr = nullptr;

		public:

			using iterator_category = std::random_access_iterator_tag;
			using value_type = ty;
			using difference_type = std::ptrdiff_t;
			using pointer = const ty*;
			using reference = const ty&;

			const_iterator(const pointer& it_pointer) : ptr(it_pointer) {}

			reference operator*() const { return *ptr; }
			const_pointer operator->() const { return ptr; }

			PSTD::array<ty, m_size>::const_iterator& operator++() {
				ptr++;
				return *this;
			}
			PSTD::array<ty, m_size>::const_iterator operator++(int) {
				return PSTD::array<ty, m_size>::const_iterator(ptr++);
			}

			PSTD::array<ty, m_size>::const_iterator& operator--() {
				ptr--;
				return *this;
			}
			PSTD::array<ty, m_size>::const_iterator operator--(int) {
				return PSTD::array<ty, m_size>::const_iterator(ptr--);
			}

			bool operator == (const PSTD::array<ty, m_size>::const_iterator& other) const {
				return ptr == other.ptr;
			}
			bool operator != (const PSTD::array<ty, m_size>::const_iterator& other) const {
				return ptr != other.ptr;
			}
			bool operator <= (const PSTD::array<ty, m_size>::const_iterator& other) const {
				return ptr <= other.ptr;
			}
			bool operator >= (const PSTD::array<ty, m_size>::const_iterator& other) const {
				return ptr >= other.ptr;
			}
			bool operator < (const PSTD::array<ty, m_size>::const_iterator& other) const {
				return ptr < other.ptr;
			}
			bool operator > (const PSTD::array<ty, m_size>::const_iterator& other) const {
				return ptr > other.ptr;
			}

			PSTD::array<ty, m_size>::const_iterator operator+(const int& n) const {
				return PSTD::array<ty, m_size>::const_iterator(ptr + n);
			}
			PSTD::array<ty, m_size>::const_iterator operator-(const int& n) const {
				return PSTD::array<ty, m_size>::const_iterator(ptr - n);
			}

			PSTD::array<ty, m_size>::const_iterator& operator+= (const int& n) {
				ptr += n; return *this;
			}
			PSTD::array<ty, m_size>::const_iterator& operator-= (const int& n) {
				ptr -= n; return *this;
			}

			difference_type operator-(const PSTD::array<ty, m_size>::const_iterator& other) const {
				return ptr - other.ptr;
			}
			/*operator[]*/ty& operator[] (const int& n) const {
				return ptr[n];
			}
		};

		using reverse_iterator = std::reverse_iterator<PSTD::array<ty, m_size>::iterator>;

		using const_reverse_iterator = std::reverse_iterator<PSTD::array<ty, m_size>::const_iterator>;

		PSTD::array<ty, m_size>::iterator begin() {
			return PSTD::array<ty, m_size>::iterator(internal_array);
		}
		PSTD::array<ty, m_size>::iterator end() {
			return PSTD::array<ty, m_size>::iterator(internal_array + m_size);
		}

		PSTD::array<ty, m_size>::const_iterator cbegin() {
			return PSTD::array<ty, m_size>::const_iterator(internal_array);
		}
		PSTD::array<ty, m_size>::const_iterator cend() {
			return PSTD::array<ty, m_size>::const_iterator(internal_array + m_size);
		}

		PSTD::array<ty, m_size>::reverse_iterator rbegin() {
			return PSTD::array<ty, m_size>::reverse_iterator(this->end());
		}
		PSTD::array<ty, m_size>::reverse_iterator rend() {
			return PSTD::array<ty, m_size>::reverse_iterator(this->begin());
		}

		PSTD::array<ty, m_size>::const_reverse_iterator crbegin() {
			return PSTD::array<ty, m_size>::const_reverse_iterator(this->cend());
		}
		PSTD::array<ty, m_size>::const_reverse_iterator crend() {
			return PSTD::array<ty, m_size>::const_reverse_iterator(this->cbegin());
		}


		/* operator [] */ty& operator[] (size_t index) {
			return internal_array[index];
		}
		/* operator [] */const ty& operator[] (size_t index)const {
			return internal_array[index];
		}

		ty& at(size_t index) {
			return internal_array[index];
		}
		const ty& at(size_t index) const {
			return internal_array[index];
		}


		ty& front(size_t index) {
			return internal_array[0];
		}
		const ty& front(size_t index) const {
			return internal_array[0];
		}

		ty& back() {
			return internal_array[m_size - 1];
		}
		const ty& back() const {
			return internal_array[m_size - 1];
		}


		ty* data() {
			return &internal_array[0];
		}
		const ty* data() const {
			return &internal_array[0];
		}

		ty& ring_acess(size_t index) {
			if (m_size == 0) { throw std::logic_error("The size of smart_array cannot be zero when it is acessed"); }
			return internal_array[index % m_size];
		}
		const ty& ring_acess(size_t index) const {
			if (m_size == 0) { throw std::logic_error("The size of smart_array cannot be zero when it is acessed"); }
			return internal_array[index % m_size];
		}


		void swap(PSTD::array<ty, m_size>& other) noexcept {
			for (size_t i = 0; i < m_size; i++) {
				std::swap(this->internal_array[i], other.internal_array[i]);
			}
		}
		void fill(const ty& value) noexcept {
			for (size_t i = 0; i < m_size; i++) {
				internal_array[i] = value;
			}
		}

		constexpr size_t size() const noexcept { return m_size; }
		constexpr size_t max_size() const noexcept { return m_size; }
		constexpr bool empty()const noexcept { return m_size == 0; }

		bool operator==(PSTD::array<ty, m_size>& rhs) const {
			for (size_t i = 0; i < m_size; ++i) {
				if (internal_array[i] != rhs[i]) { return false; }
			}
			return true;
		}
		bool operator!=(PSTD::array<ty, m_size>& rhs) const {
			for (size_t i = 0; i < m_size; ++i) {
				if (internal_array[i] != rhs[i]) { return true; }
			}
			return false;
		}
		bool operator<(PSTD::array<ty, m_size>& rhs) const {
			return std::lexicographical_compare(this->cbegin(), this->cend(), rhs.cbegin(), rhs.cend(), std::less<ty>());
		}
		bool operator>(PSTD::array<ty, m_size>& rhs) const {
			return std::lexicographical_compare(this->cbegin(), this->cend(), rhs.cbegin(), rhs.cend(), std::greater<ty>());
		}
		bool operator<=(PSTD::array<ty, m_size>& rhs) const {
			return std::lexicographical_compare(this->cbegin(), this->cend(), rhs.cbegin(), rhs.cend(), std::less_equal<ty>());
		}
		bool operator>=(PSTD::array<ty, m_size>& rhs) const {
			return std::lexicographical_compare(this->cbegin(), this->cend(), rhs.cbegin(), rhs.cend(), std::greater_equal<ty>());
		}


		array() = default;
		array(array&& move) = default;
		array(array& copy) = default;
		

	};

#if !defined(PSTD_DATA_STRUCTURE_NO_OSTREAM)
	template <class t, size_t m_size>
	std::ostream& operator<<(std::ostream& os, PSTD::array<t, m_size>& arr) {
		os << '[';
		if (!arr.empty()) {
			os << arr[0];
			for (size_t i = 1; i < m_size; i++) {
				os << ", " << arr[i];
			}

		}

		os << ']';
		return os;
	}
#endif

#if !defined(PSTD_DATA_STRUCTURE_NO_OSTREAM)
	//Classe de teste, a mesma age como o tipo nativo t. Porém a mesma gera saidas de console ao longo do processo
	template <typename t>
	class lifetime {
		t val = {};

	public:

		lifetime() {
			val = {};
			std::cerr << "PSTD::lifetime<" << typeid(t).name() << "> default constructor\n";
		}
		lifetime(const t& value) {
			val = value;
			std::cerr << "PSTD::lifetime<" << typeid(t).name() << "> value constructor\n";
		}
		lifetime(lifetime<t>& copy) : val(copy.val) {
			val = copy.val;
			std::cerr << "PSTD::lifetime<" << typeid(t).name() << "> copy constructor\n";
		}
		lifetime(lifetime<t>&& move) noexcept : val(move.val) {
			val = std::move(move.val);
			std::cerr << "PSTD::lifetime<" << typeid(t).name() << "> move constructor\n";
		}
		template <typename... Args> lifetime(Args&&... args) : val(std::forward<Args>(args)...) {
			val = t(std::forward<Args>(args)...);

			std::cerr << "PSTD::lifetime<" << typeid(t).name() << "> (args) constructor\n";

		}
		~lifetime() {
			std::cerr << "PSTD::lifetime<" << typeid(t).name() << "> destructor\n";
		}


		lifetime<t> operator= (const lifetime<t>& other) {
			val = other.val;
			return *this;
		}
		lifetime<t> operator= (lifetime<t>&& other) noexcept {
			val = other.val;
			return *this;
		}

		operator t& () { return val; }
		operator const t& ()const { return val; }
	};
#endif 

	template <class t, class Alloc = std::allocator<t>>
	class smart_array {

		size_t m_size = 0;
		size_t m_capacity = 0;
		t* arr = nullptr;

		Alloc alloc;
		using traits = std::allocator_traits<Alloc>;

	private:
		//for when is geting bigger

		// change the size of the array, moving a shllow copy to the new allocation.
		void Realoc(const size_t& new_capacity) {
			t* ptr = nullptr;

			ptr = traits::allocate(alloc, new_capacity);
			//(t*)(::operator new(new_capacity * sizeof(t)));



			size_t i;
			for (i = 0; i < m_size; i++) {
				ptr[i] = std::move(arr[i]);
			}


			traits::deallocate(alloc, arr, m_capacity);

			arr = ptr;
			m_capacity = new_capacity;
		}

		void Clean_slate(size_t new_capacity) {
			traits::deallocate(alloc, arr, m_capacity);
			m_capacity = new_capacity;
			arr = traits::allocate(alloc, m_capacity);
		}

		void move_array(PSTD::smart_array<t, Alloc>& array) {
			arr = array.arr;
			m_size = array.m_size;
			m_capacity = array.m_capacity;

			arr = nullptr;
			m_size = 0;
			m_capacity = 0;
		}

		void copy_array(const PSTD::smart_array<t, Alloc>& array) {
			if (array.m_size > m_capacity) {
				traits::deallocate(alloc, arr, m_capacity);
				m_capacity = array.m_size > 2 ? array.m_size : 2;
				arr = traits::allocate(alloc, m_capacity);
			}

			m_size = array.m_size;
			for (size_t i = 0; i < m_size; i++) {
				traits::construct(alloc, arr + i, array[i]);
			}
		}

		void move_if_possible(PSTD::smart_array<t, Alloc>&& array, std::true_type) noexcept {
			this->move_array(array);
		}
		void move_if_possible(PSTD::smart_array<t, Alloc>&& other, std::false_type) noexcept {
			if (alloc == other.alloc) {
				this->move_array(other);
			}
			else {
				this->copy_array(other);
			}
		}

	public:
		using value_type = t;

		using size_type = size_t;
		using difference_type = std::ptrdiff_t;
		using reference = t&;
		using const_reference = const t&;
		using pointer = value_type*;
		using const_pointer = const value_type*;
		using const_pointer_reference = PSTD::smart_array<t, Alloc>::const_pointer&;

		// iterator

		class iterator {
			t* ptr = nullptr;

		public:

			using iterator_category = std::random_access_iterator_tag;
			using value_type = t;
			using difference_type = std::ptrdiff_t;
			using pointer = t*;
			using reference = t&;

			iterator(const pointer& it_pointer) : ptr(it_pointer) {}

			//operator PSTD::smart_array<t, Alloc>::const_iterator() { return PSTD::smart_array<t, Alloc>::const_iterator(ptr); }

			reference operator*() const { return *ptr; }
			const_pointer operator->() const { return ptr; }

			PSTD::smart_array<t, Alloc>::iterator& operator++() {
				ptr++;
				return *this;
			}
			PSTD::smart_array<t, Alloc>::iterator operator++(int) {
				return PSTD::smart_array<t, Alloc>::iterator(ptr++);
			}

			PSTD::smart_array<t, Alloc>::iterator& operator--() {
				ptr--;
				return *this;
			}
			PSTD::smart_array<t, Alloc>::iterator operator--(int) {
				return PSTD::smart_array<t, Alloc>::iterator(ptr--);
			}

			bool operator == (const PSTD::smart_array<t, Alloc>::iterator& other) const {
				return ptr == other.ptr;
			}
			bool operator != (const PSTD::smart_array<t, Alloc>::iterator& other) const {
				return ptr != other.ptr;
			}
			bool operator <= (const PSTD::smart_array<t, Alloc>::iterator& other) const {
				return ptr <= other.ptr;
			}
			bool operator >= (const PSTD::smart_array<t, Alloc>::iterator& other) const {
				return ptr >= other.ptr;
			}
			bool operator < (const PSTD::smart_array<t, Alloc>::iterator& other) const {
				return ptr < other.ptr;
			}
			bool operator > (const PSTD::smart_array<t, Alloc>::iterator& other) const {
				return ptr > other.ptr;
			}

			PSTD::smart_array<t, Alloc>::iterator operator+(const int& n) const {
				return PSTD::smart_array<t, Alloc>::iterator(ptr + n);
			}
			PSTD::smart_array<t, Alloc>::iterator operator-(const int& n) const {
				return PSTD::smart_array<t, Alloc>::iterator(ptr - n);
			}

			PSTD::smart_array<t, Alloc>::iterator& operator+= (const int& n) {
				ptr += n; return *this;
			}
			PSTD::smart_array<t, Alloc>::iterator& operator-= (const int& n) {
				ptr -= n; return *this;
			}

			difference_type operator-(const PSTD::smart_array<t, Alloc>::iterator& other) const {
				return ptr - other.ptr;
			}
			/*operator[]*/t& operator[] (const int& n) const {
				return ptr[n];
			}


		};

		class const_iterator {
			const t* ptr = nullptr;

		public:

			using iterator_category = std::random_access_iterator_tag;
			using value_type = t;
			using difference_type = std::ptrdiff_t;
			using pointer = const value_type*;
			using reference = const value_type&;

			const_iterator(pointer const& it_pointer) : ptr(it_pointer) {}
			const_iterator(PSTD::smart_array<t, Alloc>::iterator it) : ptr(&(*it)) {}

			reference operator*() const { return *ptr; }
			pointer operator->() const { return ptr; }

			PSTD::smart_array<t, Alloc>::const_iterator& operator++() {
				ptr++;
				return *this;
			}
			PSTD::smart_array<t, Alloc>::const_iterator operator++(int) {
				return PSTD::smart_array<t, Alloc>::const_iterator(ptr++);
			}

			PSTD::smart_array<t, Alloc>::const_iterator& operator--() {
				ptr--;
				return *this;
			}
			PSTD::smart_array<t, Alloc>::const_iterator operator--(int) {
				return PSTD::smart_array<t, Alloc>::const_iterator(ptr--);
			}

			bool operator == (const PSTD::smart_array<t, Alloc>::const_iterator& other) const {
				return ptr == other.ptr;
			}
			bool operator != (const PSTD::smart_array<t, Alloc>::const_iterator& other) const {
				return ptr != other.ptr;
			}
			bool operator <= (const PSTD::smart_array<t, Alloc>::const_iterator& other) const {
				return ptr <= other.ptr;
			}
			bool operator >= (const PSTD::smart_array<t, Alloc>::const_iterator& other) const {
				return ptr >= other.ptr;
			}
			bool operator < (const PSTD::smart_array<t, Alloc>::const_iterator& other) const {
				return ptr < other.ptr;
			}
			bool operator > (const PSTD::smart_array<t, Alloc>::const_iterator& other) const {
				return ptr > other.ptr;
			}

			PSTD::smart_array<t, Alloc>::const_iterator operator+(const int& n) const {
				return PSTD::smart_array<t, Alloc>::const_iterator(ptr + n);
			}
			PSTD::smart_array<t, Alloc>::const_iterator operator-(const int& n) const {
				return PSTD::smart_array<t, Alloc>::const_iterator(ptr - n);
			}

			PSTD::smart_array<t, Alloc>::const_iterator& operator+= (const int& n) {
				ptr += n; return *this;
			}
			PSTD::smart_array<t, Alloc>::const_iterator& operator-= (const int& n) {
				ptr -= n; return *this;
			}

			difference_type operator-(const PSTD::smart_array<t, Alloc>::const_iterator& other) const {
				return ptr - other.ptr;
			}
			/*operator[]*/const t& operator[] (int n) const {
				return *(ptr + n);
			}
		};

		using reverse_iterator = std::reverse_iterator<iterator>;

		using const_reverse_iterator = std::reverse_iterator<PSTD::smart_array<t, Alloc>::const_iterator>;

		PSTD::smart_array<t, Alloc>::iterator begin() {
			return PSTD::smart_array<t, Alloc>::iterator(arr);
		}
		PSTD::smart_array<t, Alloc>::iterator end() {
			return PSTD::smart_array<t, Alloc>::iterator(arr + m_size);
		}

		PSTD::smart_array<t, Alloc>::const_iterator cbegin() const {
			return PSTD::smart_array<t, Alloc>::const_iterator(arr);
		}
		PSTD::smart_array<t, Alloc>::const_iterator cend() const {
			return PSTD::smart_array<t, Alloc>::const_iterator(arr + m_size);
		}


		PSTD::smart_array<t, Alloc>::reverse_iterator rbegin() {
			return PSTD::smart_array<t, Alloc>::reverse_iterator(this->end());
		}
		PSTD::smart_array<t, Alloc>::reverse_iterator rend() {
			return PSTD::smart_array<t, Alloc>::reverse_iterator(this->begin());
		}

		PSTD::smart_array<t, Alloc>::const_reverse_iterator crbegin() const {
			return PSTD::smart_array<t, Alloc>::const_reverse_iterator(this->cend());
		}
		PSTD::smart_array<t, Alloc>::const_reverse_iterator crend() const {
			return PSTD::smart_array<t, Alloc>::const_reverse_iterator(this->cbegin());
		}

		//controle

		void clear() {
			while (m_size > 0) {
				--m_size;
				traits::destroy(alloc, &arr[m_size]);
			}
		}

		void push_back(const t& value) {
			if (m_size >= m_capacity) { // >= inves de == por segurança adicinal
				this->Realoc(m_size == 0 ? 2 : m_capacity + (m_capacity >> 1));
			}

			traits::construct(alloc, &arr[m_size], value);
			m_size++;
		}
		void push_back(t&& value) {
			if (m_size >= m_capacity) {
				this->Realoc(m_size == 0 ? 2 : m_capacity + (m_capacity >> 1));
			}

			traits::construct(alloc, &arr[m_size], std::move(value));
			m_size++;
		}

		void pop_back() {
			if (m_size > 0) {
				m_size--;
				traits::destroy(alloc, &arr[m_size]);
			}
		}
		void trim_back(size_t trim) {
			for (size_t i = 1; i <= m_size && i <= trim; ++i) {
				traits::destroy(alloc, arr + (m_size - i));
			}

			m_size -= (trim > m_size) ? m_size : trim;
		}

		template <typename... Args> void emplace_back(Args&&... args) {
			if (m_size >= m_capacity) {
				this->Realoc(m_size == 0 ? 2 : m_capacity + (m_capacity >> 1));
			}

			traits::construct(alloc, &arr[m_size], args...);
		}

		// makes the smart array grow n elements
		void reserve_n(const size_t& n_val) {
			// make it grow n_val elements
			Realoc(m_capacity + n_val);
		}
		// makes the amart array until it has n elements avalaible
		void reserve_until(const size_t& n_val) {
			// reserves memory only if the smart array don´t have the necessary capacity to conport new n_val elementes
			if (n_val > reserved()) {
				Realoc(n_val + m_size);
			}
		}
		// resize to eliminate any extra reserved memory, mantaining the minimal allocation of 2 elements
		void shrink_to_fit() {
			if (m_size < 2) {
				this->Realoc(2);
				return;
			}
			this->Realoc(m_size);
		}

		// Resize the array if necessary, to make it have the value val repeated n amount of times
		void assign(const size_t& times, const t& val = {}) {
			clear();
			if (times > m_capacity) {
				this->Clean_slate(times > 2 ? times : 2);
			}

			for (m_size = 0; m_size < times; m_size++) {
				traits::construct(alloc, arr + m_size, val);
			}
		}
		// Resize the array if necessary, to make it have the value constructed from args repeated n amount of times
		template <typename... Args> void assign(const size_t& times, Args&&... args) {
			clear();
			if (times > m_capacity) {
				this->Clean_slate(times > 2 ? times : 2);
			}

			for (m_size = 0; m_size < times; m_size++) {
				traits::construct(alloc, arr + m_size, args...);
			}
		}
		void assign(std::initializer_list<t> list) {
			m_size = list.size();

			if (list.size() > m_capacity) {
				this->Clean_slate(list.size() > 2 ? list.size() : 2);
			}

			size_t i = 0;
			for (const auto& lit : list) {
				traits::construct(alloc, arr + i, lit);
				++i;
			}
		}
		// Copy the data from the range [first, last) to smart array
		template <class _InIt> void assign(_InIt first, _InIt last) {
			m_size = std::distance(first, last);

			if (m_size >= m_capacity) {
				this->Clean_slate(m_size > 2 ? m_size : 2);
			}

			size_t i = 0;
			while (first < last) {
				traits::construct(alloc, arr + i, *first);
				++first;
				++i;
			}
		}
		// Copy the data from the container and copy it to the smart array
		template <class _Container> void assign(_Container& container) {

			using _InIt = decltype(*container.begin());
			this->assign<_InIt>(container.begin(), container.end());
		}


		void swap(smart_array& other) noexcept(traits::propagate_on_container_swap::value || traits::is_always_equal::value) {
			if (traits::propagate_on_container_swap::value) {
				std::swap(arr, other.arr);
				std::swap(m_size, other.m_size);
				std::swap(m_capacity, other.m_capacity);
				std::swap(alloc, other.alloc);
			}
			else if (this->alloc == other.alloc) {
				std::swap(arr, other.arr);
				std::swap(m_size, other.m_size);
				std::swap(m_capacity, other.m_capacity);
			}
			else {
				PSTD::smart_array<t, Alloc> tmp(std::move(*this));
				*this = std::move(other);
				other = std::move(tmp);
			}
		}


		void resize(const size_t& count) {
			// if size is equal to the target size, does nothing
			if (m_size == count) { return; }
			// if count is bigger than size the array must grow
			if (count > m_size) {
				// if the array don't has the necessary capacity, more memory is allocated
				if (count > m_capacity) {
					this->Realoc(count);
				}
				// grow the array and initializes the memory
				while (m_size < count) {
					traits::construct(alloc, arr + m_size);
					m_size++;
				}
			}
			// if ciunt is smaller than size the array must shirink
			else {
				// clear the elements until the new size
				while (m_size > count) {
					m_size--; // destroy after the -- operator, because the first position is the index 0
					traits::destroy(alloc, arr + m_size);
				}
			}
		}
		void resize(const size_t& count, const t& value) {
			if (m_size == count) { return; }
			if (count > m_size) {
				if (count > m_capacity) {
					this->Realoc(count);
				}
				while (m_size < count) {
					traits::construct(alloc, arr + m_size, value);
					m_size++;
				}
			}
			else {
				while (m_size > count) {
					m_size--;// destroy after the -- operator, because the first position is the index 0
					traits::destroy(alloc, arr + m_size);
				}
			}
		}
		template <typename... Args>
		void resize(const size_t& count, Args&&... args) {
			if (m_size == count) { return; }
			if (count > m_size) {
				if (count > m_capacity) {
					this->Realoc(count);
				}
				while (m_size < count) {
					traits::construct(alloc, arr + m_size, args...);
					m_size++;
				}
			}
			else {
				while (m_size > count) {
					m_size--;
					traits::destroy(alloc, arr + m_size);
				}
			}
		}


		void erase(const size_t& index) {
			if (index >= this->m_size) { return; }

			traits::destroy(alloc, arr + index);

			for (size_t loop = index; loop < m_size - 1; ++loop) {
				arr[loop] = std::move(arr[loop + 1]);
			}

			--m_size;
		}
		void erase(const size_t& inf, const size_t& sup) {
			// refazer
			size_t offset = sup - inf;

			if (inf > sup || inf > m_size || sup > m_size) {
				return;
			}
			// 
			for (size_t loop = inf; loop + offset < m_size; ++loop) {
				arr[loop].~t();
				arr[loop] = std::move(arr[loop + offset]);
			}

			m_size -= sup - inf;
		}

		void erase(PSTD::smart_array<t, Alloc>::const_iterator _where) {
			size_t index = _where - this->cbegin();

			if (index >= this->m_size) { return; }

			traits::destroy(alloc, arr + index);

			for (size_t loop = index; loop < m_size - 1; ++loop) {
				arr[loop] = std::move(arr[loop + 1]);
			}

			--m_size;
		}
		void erase(PSTD::smart_array<t, Alloc>::const_iterator _first, PSTD::smart_array<t, Alloc>::const_iterator _last) {
			size_t offset = _last - _first;
			size_t inf = _first - this->begin();
			size_t sup = _last - this->begin();


			if (inf > sup || inf > m_size || sup > m_size) {
				return;
			}
			// 
			for (size_t loop = inf; loop + offset < m_size; ++loop) {
				arr[loop].~t();
				arr[loop] = std::move(arr[loop + offset]);
			}

			m_size -= sup - inf;
		}


		PSTD::smart_array<t, Alloc>::iterator insert(size_type pos, const t& value) {

			if (m_size >= m_capacity) {
				t* arr_aux = traits::allocate(alloc, m_size + 1);

				for (size_t i = 0; i < pos; i++) {
					arr_aux[i] = std::move(arr[i]);
				}

				for (size_t i = m_size; i > pos; i--) {
					arr_aux[i] = std::move(arr[i - 1]);
				}

				traits::deallocate(alloc, arr, m_capacity);

				m_capacity = m_size = m_size + 1;
				arr = arr_aux;

				traits::construct(alloc, arr + pos, value);

				return PSTD::smart_array<t, Alloc>::iterator(arr + pos);
			}

			for (size_t i = m_size; i > pos; i--) {
				arr[i] = std::move(arr[i - 1]);
			}

			traits::construct(alloc, arr + pos, value);

			m_size++;

			return PSTD::smart_array<t, Alloc>::iterator(arr + pos);
		}
		PSTD::smart_array<t, Alloc>::iterator insert(size_type pos, t&& value) {
			if (m_size >= m_capacity) {
				t* arr_aux = traits::allocate(alloc, m_size + 1); //(t*) operator new((m_size + 1) * sizeof(t));

				for (size_t i = 0; i < pos; i++) {
					arr_aux[i] = std::move(arr[i]);
				}

				for (size_t i = m_size; i > pos; i--) {
					arr_aux[i] = std::move(arr[i - 1]);
				}


				traits::deallocate(alloc, arr, m_capacity);

				m_capacity = m_size = m_size + 1;

				arr = arr_aux;

				traits::construct(alloc, arr + pos, value);

				return PSTD::smart_array<t, Alloc>::iterator(arr + pos);
			}

			for (size_t i = m_size; i > pos; i--) {
				arr[i] = std::move(arr[i - 1]);
			}

			traits::construct(alloc, arr + pos, value);

			m_size++;

			return PSTD::smart_array<t, Alloc>::iterator(arr + pos);
		}
		PSTD::smart_array<t, Alloc>::iterator insert(size_type pos, size_type count, const t& value) {

			if (m_size + count >= m_capacity) {
				t* arr_aux = traits::allocate(alloc, m_size + count);
				//(t*) operator new((m_size + count) * sizeof(t));

				for (size_t i = 0; i < pos; i++) {
					arr_aux[i] = std::move(arr[i]);
				}

				for (size_t i = m_size - 1 + count; i > pos; i--) {
					arr_aux[i] = std::move(arr[i - count]);
				}

				for (size_t i = pos; i < pos + count; i++) {
					traits::construct(alloc, arr_aux + i, value);
				}

				traits::deallocate(alloc, arr, m_capacity);

				m_size += count;
				m_capacity = m_size;

				arr = arr_aux;

				return PSTD::smart_array<t, Alloc>::iterator(arr + pos);
			}

			for (size_t i = m_size - 1 + count; i > pos; i--) {
				arr[i] = std::move(arr[i - count]);
			}

			for (size_t i = pos; i < pos + count; i++) {
				traits::construct(alloc, arr + i, value);
			}

			m_size += count;

			return PSTD::smart_array<t, Alloc>::iterator(arr + pos);
		}
		template< class InputIt, std::enable_if_t<!std::is_integral_v<InputIt>, int> = 0> PSTD::smart_array<t, Alloc>::iterator insert(size_type pos, InputIt first, InputIt last) {
			size_t count = std::distance(first, last);


			if (m_size + count >= m_capacity) {
				t* arr_aux = traits::allocate(alloc, m_size + count);
				//(t*) operator new((m_size + count) * sizeof(t));

				for (size_t i = 0; i < pos; i++) {
					arr_aux[i] = std::move(arr[i]);
				}

				for (size_t i = m_size - 1 + count; i > pos; i--) {
					arr_aux[i] = std::move(arr[i - count]);
				}

				for (size_t i = pos; i < pos + count; ++i, ++first) {
					traits::construct(alloc, arr_aux + i, *first);
				}

				traits::deallocate(alloc, arr, m_capacity);

				m_size += count;
				m_capacity = m_size;

				arr = arr_aux;

				return PSTD::smart_array<t, Alloc>::iterator(arr + pos);
			}

			for (size_t i = m_size - 1 + count; i > pos; i--) {
				arr[i] = std::move(arr[i - count]);
			}

			for (size_t i = pos; i < pos + count; ++i, ++first) {
				traits::construct(alloc, arr + i, *first);
			}

			m_size += count;

		}
		template< class _Container > PSTD::smart_array<t, Alloc>::iterator insert(size_type pos, _Container& container) {
			return this->insert(pos, container.begin(), container.end());
		}
		PSTD::smart_array<t, Alloc>::iterator insert(size_type pos, std::initializer_list<t> list) {
			size_t count = list.size();
			auto first = list.begin();

			if (m_size + count >= m_capacity) {
				t* arr_aux = traits::allocate(alloc, m_size + 1);

				for (size_t i = 0; i < pos; i++) {
					arr_aux[i] = std::move(arr[i]);
				}

				for (size_t i = m_size - 1 + count; i > pos; i--) {
					arr_aux[i] = std::move(arr[i - count]);
				}

				for (size_t i = pos; i < pos + count; ++i, ++first) {
					traits::construct(alloc, arr + i, *first);
				}

				traits::deallocate(alloc, arr, m_capacity);

				m_size += count;
				m_capacity = m_size;

				arr = arr_aux;

				return PSTD::smart_array<t, Alloc>::iterator(arr + pos);
			}

			for (size_t i = m_size - 1 + count; i > pos; i--) {
				arr[i] = std::move(arr[i - count]);
			}

			for (size_t i = pos; i < pos + count; ++i, ++first) {
				traits::construct(alloc, arr + i, *first);
			}

			m_size += count;
			return this->insert(pos, list.begin(), list.end());
		}

		PSTD::smart_array<t, Alloc>::iterator insert(PSTD::smart_array<t, Alloc>::const_iterator pos, const t& value) {
			return this->insert(pos - this->cbegin(), value);
		}
		PSTD::smart_array<t, Alloc>::iterator insert(PSTD::smart_array<t, Alloc>::const_iterator pos, t&& value) {
			return this->insert(pos - this->cbegin(), value);
		}
		PSTD::smart_array<t, Alloc>::iterator insert(PSTD::smart_array<t, Alloc>::const_iterator pos, size_type count, const t& value) {
			return this->insert(pos - this->cbegin(), count, value);
		}
		template< class InputIt, std::enable_if_t<!std::is_integral_v<InputIt>, int> = 0 >\
			PSTD::smart_array<t, Alloc>::iterator insert(PSTD::smart_array<t, Alloc>::const_iterator pos, InputIt first, InputIt last) {
			return this->insert(pos - this->cbegin(), first, last);
		}
		template< class _Container > PSTD::smart_array<t, Alloc>::iterator insert(PSTD::smart_array<t, Alloc>::const_iterator pos, _Container& container) {
			using iterator = decltype(*container.begin());
			return this->insert<iterator>(pos - this->cbegin(), container.begin(), container.end());
		}
		PSTD::smart_array<t, Alloc>::iterator insert(PSTD::smart_array<t, Alloc>::const_iterator pos, std::initializer_list<t> list) {
			return this->insert(pos - this->cbegin(), list);
		}


		//acesso

		/*operator []*/t& operator[] (size_t index) {
			if (index >= m_size) {
				throw std::out_of_range("tryied to acess element " + std::to_string(index) + ", while array size is " + std::to_string(m_size));
			}
			return arr[index];
		}
		/*operator []*/const t& operator[] (size_t index) const {
			if (index >= m_size) {
				throw std::out_of_range("tryied to acess element " + std::to_string(index) + ", while array size is " + std::to_string(m_size));
			}
			return arr[index];
		}

		t& at(size_t index) {
			if (index >= m_size) {
				throw std::out_of_range("tryied to acess element " + std::to_string(index) + ", while array size is " + std::to_string(m_size));
			}
			return arr[index];
		}
		const t& at(size_t index) const {
			if (index >= m_size) {
				throw std::out_of_range("tryied to acess element " + std::to_string(index) + ", while array size is " + std::to_string(m_size));
			}
			return arr[index];
		}


		// versions that suport  arr[-1] to acess the last element

		/*operator []*/t& operator[] (int32_t index) {
			if (index < 0) {
				//negative
				if (size_t(-index) > m_size) { throw std::out_of_range("tryied to acess element " + std::to_string(index) + ", while array size is " + std::to_string(m_size)); }
				return arr[this->m_size + index];
			}
			if (size_t(index) >= m_size) { throw std::out_of_range("tryied to acess element " + std::to_string(index) + ", while array size is " + std::to_string(m_size)); }
			return arr[index];
		}
		/*operator []*/const t& operator[] (int32_t index) const {
			if (index < 0) {
				//negative
				if (size_t(-index) > m_size) { throw std::out_of_range("tryied to acess element " + std::to_string(index) + ", while array size is " + std::to_string(m_size)); }
				return arr[this->m_size + index];
			}
			if (size_t(index) >= m_size) { throw std::out_of_range("tryied to acess element " + std::to_string(index) + ", while array size is " + std::to_string(m_size)); }
			return arr[index];
		}

		t& at(int32_t index) {
			if (index < 0) {
				//negative
				if (size_t(-index) > m_size) { throw std::out_of_range("tryied to acess element " + std::to_string(index) + ", while array size is " + std::to_string(m_size)); }
				return arr[this->m_size + index];
			}
			if (size_t(index) >= m_size) { throw std::out_of_range("tryied to acess element " + std::to_string(index) + ", while array size is " + std::to_string(m_size)); }
			return arr[index];
		}
		const t& at(int32_t index) const {
			if (index < 0) {
				//negative
				if (size_t(-index) > m_size) { throw std::out_of_range("tryied to acess element " + std::to_string(index) + ", while array size is " + std::to_string(m_size)); }
				return arr[this->m_size + index];
			}
			if (size_t(index) >= m_size) { throw std::out_of_range("tryied to acess element " + std::to_string(index) + ", while array size is " + std::to_string(m_size)); }
			return arr[index];
		}


		// acess the element in the index position. Any index out of range will force the array to grow,.
		// This is a slow safety feature, do not use unless absolute necessary.
		t& safe_acess(size_t index) {
			if (index >= m_size) {
				if (index >= m_capacity) {
					this->Realoc(index + 1);
				}
				for (size_t i = m_size; i <= index; i++) {
					traits::construct(alloc, arr + i);
				}
				m_size = index + 1;
			}
			return arr[index];
		}


		t& ring_acess(size_t index) {
			if (m_size == 0) { throw std::logic_error("The size of smart_array cannot be zero when it is acessed"); }
			return arr[index % m_size];
		}
		const t& ring_acess(size_t index) const {
			if (m_size == 0) { throw std::logic_error("The size of smart_array cannot be zero when it is acessed"); }
			return arr[index % m_size];
		}

		t& back() {
			return this->arr[this->m_size - 1];
		}
		const t& back() const {
			return this->arr[this->m_size - 1];
		}

		t& front() {
			return this->arr[0];
		}
		const t& front() const {
			return this->arr[0];
		}

		Alloc get_allocator()const noexcept {
			return alloc;
		}

		//info

		size_t size_of() const noexcept { return this->m_size; }
		size_t size() const noexcept { return this->m_size; }
		size_t capacity() const noexcept { return this->m_capacity; }
		size_t reserved() const noexcept { return this->m_capacity - this->m_size; }
		size_t max_size()const noexcept { return traits::max_size(alloc); }

		bool operator== (const PSTD::smart_array<t, Alloc>& other) const {
			return std::equal(this->cbegin(), this->cend(), other.cbegin(), other.cend());
		}
		bool operator!= (const PSTD::smart_array<t, Alloc>& other) const {
			return !std::equal(this->cbegin(), this->cend(), other.cbegin(), other.cend());
		}
		bool operator<(const PSTD::smart_array<t, Alloc>& rhs) const {
			return std::lexicographical_compare(this->cbegin(), this->cend(), rhs.cbegin(), rhs.cend());
		}
		bool operator>(const PSTD::smart_array<t, Alloc>& rhs) const {
			return std::lexicographical_compare(rhs.cbegin(), rhs.cend(), this->cbegin(), this->cend());
		}
		bool operator<=(const PSTD::smart_array<t, Alloc>& rhs) const {
			return !(*this > rhs);
		}
		bool operator>=(const PSTD::smart_array<t, Alloc>& rhs) const {
			return !(*this < rhs);
		}


		bool empty() const noexcept { return this->m_size == 0; }
		bool is_out_of_range(const size_t& index)const noexcept { return index < 0 or index >= m_size; }
		bool is_invalid() const noexcept { return arr == nullptr; }

		//copia, refazer
		PSTD::smart_array<t, Alloc>& operator= (const PSTD::smart_array<t, Alloc>& other) {
			alloc = traits::select_on_container_copy_construction(other.alloc);

			this->clear(); // tira e destroi tudo

			this->copy_array(other); // alloc mais espaço se necessario e cria uma linda copia

			return *this;
		}
		PSTD::smart_array<t, Alloc>& operator= (PSTD::smart_array<t, Alloc>&& other)  noexcept {
			this->clear();
			traits::deallocate(alloc, arr, m_capacity);

			alloc = traits::select_on_container_copy_construction(other.alloc);
			this->move_if_possible(std::move(other), typename traits::is_always_equal{});
			return *this;
		}
		PSTD::smart_array<t, Alloc>& operator= (std::initializer_list<t> list) {
			clear();
			m_size = list.size();

			if (list.size() > m_capacity) {
				this->Clean_slate(list.size() > 2 ? list.size() : 2);
			}

			size_t i = 0;
			for (const auto& lit : list) {
				traits::construct(alloc, arr + i, lit);
			}
			return *this;
		}
		template <class _Container> PSTD::smart_array<t, Alloc>& operator= (_Container& container) {
			using _InIt = typename _Container::iterator;

			this->clear();

			m_size = std::distance(container.begin(), container.end());

			if (m_size > m_capacity) {
				this->clean_slate(m_size > 2 ? m_size : 2);
			}

			_InIt it = container.begin();

			for (size_t i = 0; i < m_size; i++, ++it) {
				traits::construct(alloc, arr + i, *it);
			}
		}


		// internos

		t* data() noexcept {
			return this->arr;
		}
		const t* data() const noexcept {
			return this->arr;
		}

		//construcao

		smart_array() : m_size(0), m_capacity(2), alloc(std::allocator<t>()) {
			arr = traits::allocate(alloc, m_capacity);
		}
		explicit smart_array(const Alloc& _alloc) : m_size(0), m_capacity(2), alloc(_alloc) {
			arr = traits::allocate(alloc, m_capacity);
		}
		explicit smart_array(size_t size, const Alloc& _alloc = std::allocator<t>()) : m_size(size), m_capacity(size > 2 ? size : 2), alloc(_alloc) {
			arr = traits::allocate(alloc, m_capacity);
			for (size_t i = 0; i < m_size; i++) {
				traits::construct(alloc, arr + i);
			}
		}
		explicit smart_array(size_t size, const t& val, const Alloc& _alloc = std::allocator<t>()) : m_size(size), m_capacity(size > 2 ? size : 2), alloc(_alloc) {
			arr = traits::allocate(alloc, m_capacity);
			for (size_t i = 0; i < size; i++) {
				traits::construct(alloc, arr + i, val);
			}
		}

		smart_array(PSTD::smart_array<t, Alloc>& other) : alloc(traits::select_on_container_copy_construction(other.alloc)) {
			this->copy_array(other);
		}
		smart_array(PSTD::smart_array<t, Alloc>&& other) noexcept : alloc(traits::select_on_container_copy_construction(other.alloc)) {
			this->move_if_possible(std::move(other), typename traits::is_always_equal{});
		}
		smart_array(PSTD::smart_array<t, Alloc>& other, const Alloc& _alloc) : alloc(_alloc) {
			this->copy_array(other);
		}
		smart_array(PSTD::smart_array<t, Alloc>&& other, const Alloc& _alloc) noexcept : alloc(_alloc) {
			this->move_if_possible(std::move(other), typename traits::is_always_equal{});
		}

		smart_array(std::initializer_list<t> list, const Alloc& _alloc = std::allocator<t>()) : m_size(list.size()), m_capacity(m_size < 2 ? 2 : m_size), alloc(_alloc) {
			// by capacity being size my 2, guarantes that the minimum alocation is 2
			arr = traits::allocate(alloc, m_capacity);
			size_t i = 0;
			for (const auto& lit : list) {
				traits::construct(alloc, arr + i, lit);
				i++;
			}
		}

		template <class _InIt, std::enable_if_t<!std::is_integral_v<_InIt>, int> = 0>
		smart_array(_InIt first, _InIt last, const Alloc& _alloc = std::allocator<t>()) : m_size(std::distance(first, last)), m_capacity(m_size > 2 ? m_size : 2), alloc(_alloc) {

			arr = traits::allocate(alloc, m_capacity);

			for (size_t i = 0; i < m_size; i++, ++first) {
				traits::construct(alloc, arr + i, *first);
			}
		}

		template <class _Container>
		smart_array(_Container& container, const Alloc& _alloc = std::allocator<t>()) : m_size(std::distance(container.begin(), container.end())), m_capacity(m_size > 2 ? m_size : 2), alloc(_alloc) {
			using _InIt = decltype(*container.begin());

			arr = traits::allocate(alloc, m_capacity);
			_InIt it = container.begin();

			for (size_t i = 0; i < m_capacity; ++i, ++it) {
				traits::construct(alloc, arr + i, *it);
			}

		}


		//destrutor

		~smart_array() {
			clear();
			traits::deallocate(alloc, arr, m_capacity);
		}

		// amigos

	};

#if !defined(PSTD_DATA_STRUCTURE_NO_OSTREAM)
	template <class t, class Alloc = std::allocator<t>>
	std::ostream& operator<<(std::ostream& os, PSTD::smart_array<t, Alloc>& arr) {
		os << '[';
		if (!arr.empty()) {
			os << arr[0];
			for (size_t i = 1; i < arr.size_of(); i++) {
				os << ", " << arr[i];
			}

		}

		os << ']';
		return os;
	}
#endif 

	template<class t = double, class Alloc = std::allocator<t>>
	PSTD::smart_array<t, Alloc> linspace(t inf, t sup, size_t n_elements) {

		PSTD::smart_array<t, Alloc> arr(n_elements);

		if (n_elements == 1) {
			arr[0] = inf;
			return arr;
		}

		double gain = double(sup - inf) / (n_elements - 1);

		for (size_t i = 0; i < n_elements; i++) {
			arr[i] = std::fma(gain, static_cast<double>(i), inf);
		}

		return arr;
	}
	template<size_t n_elements, class t = double>
	PSTD::array<t, n_elements> linspace(t inf, t sup) {

		PSTD::array<t, n_elements> arr = {};

		if (n_elements == 1) {
			arr[0] = inf;
			return arr;
		}

		double gain = double(sup - inf) / (n_elements - 1);

		for (size_t i = 0; i < n_elements; i++) {
			arr[i] = std::fma(gain, static_cast<double>(i), inf);
		}

		return arr;
	}
	template<typename t = double, class Alloc = std::allocator<t>>
	PSTD::smart_array<t, Alloc> arrange(t inf, t sup, t step) {
		// sup < inf + step * i
		// sup - inf < step * i
		// (sup - inf)/step < i
		// since we have that i need to be bigger than (sup - inf)/step, the ceil will be enough

		size_t n_size = std::ceil((sup - inf) / step);

		PSTD::smart_array<t, Alloc> arr(n_size);

		for (size_t i = 0; i < n_size; i++) {
			arr[i] = fma(step, i, inf);
		}

		return arr;
	}

	template< class t, class Alloc = std::allocator<t>, class U>
	typename PSTD::smart_array<t, Alloc>::size_type erase(PSTD::smart_array<t, Alloc>& arr, U value) {
		using ForwardIt = typename PSTD::smart_array<t, Alloc>::iterator;
		using Diference_type = typename PSTD::smart_array<t, Alloc>::difference_type;

		auto it = std::remove<ForwardIt, U>(arr.begin(), arr.end(), value);
		auto r = arr.end() - it;
		arr.erase(it, arr.end());
		return r;
	}

	template< class t, class Alloc = std::allocator<t>, class Func>
	typename PSTD::smart_array<t, Alloc>::size_type erase_if(PSTD::smart_array<t, Alloc>& arr, Func func) {
		using ForwardIt = typename PSTD::smart_array<t, Alloc>::iterator;
		using Diference_type = typename PSTD::smart_array<t, Alloc>::difference_type;

		auto it = std::remove_if<ForwardIt, Func>(arr.begin(), arr.end(), func);
		auto r = arr.end() - it;
		arr.erase(it, arr.end());
		return r;
	}

	template<typename t, class ForwardIt>
	void iota(ForwardIt first, ForwardIt last, t value, t step = 1) {
		for (; first != last; ++first, value += step) {
			*first = value;
		}
	}

	template<typename t, class _Container>
	void iota(_Container container, t value, t step = 1) {
		using ForwardIt = decltype(std::begin(std::declval<_Container&>()));
		return PSTD::iota<t, ForwardIt>(container.begin(), container.end(), value, step);
	}


	template <class _Container>
	class iterate {
		using IteratorType = decltype(std::begin(std::declval<_Container&>()));

		IteratorType first;
		IteratorType last;

	public:


		IteratorType begin() {
			return first;
		}

		IteratorType end() {
			return last;
		}


		iterate(_Container& container) : first(container.begin()), last(container.end()) {}
		iterate(_Container& container, size_t inf) : first(container.begin() + inf), last(container.end()) {}
		iterate(_Container& container, size_t inf, size_t sup) : first(container.begin() + inf), last(container.begin() + sup) {}
	};

	class PyRange {
		size_t inf = 0;
		size_t sup;
		size_t stp = 1;

	public:

		PyRange(size_t superior) : sup(superior) {}
		PyRange(size_t inferior, size_t superior) : inf(inferior), sup(superior) {}
		PyRange(size_t inferior, size_t superior, size_t step) : inf(inferior), sup(superior), stp(step) {}


		class fake_iterator {
			size_t val;
			size_t& stp;

		public:
			fake_iterator(size_t position, size_t& step) :val(position), stp(step) {}

			bool operator!=(const fake_iterator& fake) {
				return this->val != fake.val;
			}

			PSTD::PyRange::fake_iterator& operator++() {
				val += stp;
				return *this;
			}

			size_t& operator*() {
				return val;
			}
		};

		PSTD::PyRange::fake_iterator begin() {
			return PSTD::PyRange::fake_iterator(inf, stp);
		}

		PSTD::PyRange::fake_iterator end() {
			return PSTD::PyRange::fake_iterator(sup, stp);
		}
	};
}
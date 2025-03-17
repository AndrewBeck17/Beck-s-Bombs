class LL {
	private:
		Particle particle;
		LL* next = nullptr;
		LL* prev = nullptr;
	public:
		LL* get_next() const{
			return next;
		}
		void set_next(LL *new_next) {
			next = new_next;
		}
		LL *get_prev() const {
			return prev;
		}
		void set_prev(LL *new_prev) {
			prev = new_prev;
		}
};

class List {
	private:
		LL* head = nullptr;
		LL* tail = nullptr;
};
	



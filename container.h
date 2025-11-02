


class Ñontainer {
public:
	template <typename T> void write(T value);
	template <typename T> T read(int position);
private:
	int _oldest_pos;


};


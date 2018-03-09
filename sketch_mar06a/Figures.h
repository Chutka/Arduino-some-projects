class Figure
{
protected:
	/**
	maskX, maskY - координаты опорной точки фигуры.
	Относительно этой точки идет проверка
		на возможности: движения, поворота, очищения и отрисовки фигур.
	*/
	int maskX, maskY;

	/**
	Позиция в которой находится фигруры в данный момент времени (необходимо для вращения)
	*/
	int position;

	/**
	Может ли фигруы двигаться. Если нет, то нужно отрисовать новую фигуру или закончить игру.
	*/
	bool checkMove;
public:
	/**
	Конструктор по умолчанию
	в нем идет определение основных полей всех классов 
	maskX, maskY - координат опорных точек фигуры
	poisiton - задается начальная позиция фигуры
	checkMove - логическое поле, определяющее может ли фигуры двигаться
	*/
	Figure(int x, int y);

	/**
	Метод для движения фигуры по оси X в право.
	Принимает матрицу, по которой происходит движение и величину на которую происходит сдвиг по оси X.
	В теле метода совершается проверка на возможность движения по оси X
	*/
	void moveFigureRight(int matrix[33][10]);

	/**
	Метод для движения фигуры по оси X в право.
	Принимает матрицу, по которой происходит движение и величину на которую происходит сдвиг по оси X.
	В теле метода совершается проверка на возможность движения по оси X
	*/
	void moveFigureLeft(int matrix[33][10]);
	
	/**
	Метод для движения фигуры по оси Y.
	Принимает матрицу, по которой происходит движение.
	В теле метода совершается проверка на возможность движения по оси Y (вниз).
	Если движение возможно, то кооржината maskY уменьшается на 1 если нет, то величина checkMove становится false
	*/
	void moveFigureY(int matrix[33][10]);

	/**
	Геттер для checkMove
	*/
	bool getCheckMove();

	/**
	Геттер для maskX
	*/
	int getMaskX();

	/**
	Геттер для maskY
	*/
	int getMaskY();

	/**
	Метод для отрисовки фигуры на матрице.
	Принимает параметром саму матрицу. Необходимо переопределять в производных классах
	*/
	virtual void drawFigure(int matrix[33][10]);

	/**
	Метод для удаления фигуры с матрицы.
	Принимает параметром саму матрицу. Необходимо переопределять в производных классах
	*/
	virtual void clearFigure(int matrix[33][10]);

	/**
	Метод для поворота фигуры.
	Принимает параметром саму матрицу. Необходимо переопределять в производных классах
	*/
	virtual void rotateFigure(int matrix[33][10]);
	
	/**
	Метод для проверки на колизии справа
	Приниает параметром саму матрицу. Необходимо переопределеить в производных классах
	*/
	virtual bool checkRight(int matrix[33][10]);

	/**
	Метод для проверки на колизии слева
	Приниает параметром саму матрицу. Необходимо переопределеить в производных классах
	*/
	virtual bool checkLeft(int matrix[33][10]);

	/**
	Метод для проверки на колизии снизу
	Приниает параметром саму матрицу. Необходимо переопределеить в производных классах
	*/
	virtual bool checkBottom(int matrix[33][10]);

	/**
	Деструкто, в нем пока ничего не совершается, т.к. нет динамического выделения памяти
	*/
	~Figure();
};

class I :
  public Figure
{
public:
  I(int x, int y) : Figure(x, y) { };
  void drawFigure(int matrix[33][10]);
  void clearFigure(int matrix[33][10]);
  void rotateFigure(int matrix[33][10]);
  bool checkRight(int matrix[33][10]);
  bool checkLeft(int matrix[33][10]);
  bool checkBottom(int matrix[33][10]);

  ~I();
};

class J :
	public Figure
{
public:
	J(int x, int y) : Figure(x, y) { };
	void drawFigure(int matrix[33][10]);
	void clearFigure(int matrix[33][10]);
	void rotateFigure(int matrix[33][10]);
	bool checkRight(int matrix[33][10]);
	bool checkLeft(int matrix[33][10]);
	bool checkBottom(int matrix[33][10]);

	~J();
};

class O :
	public Figure
{
public:
	O(int x, int y) : Figure(x, y) { };
	void drawFigure(int matrix[33][10]);
	void clearFigure(int matrix[33][10]);
	void rotateFigure(int matrix[33][10]);
	bool checkRight(int matrix[33][10]);
	bool checkLeft(int matrix[33][10]);
	bool checkBottom(int matrix[33][10]);

	~O();
};
class S :
	public Figure
{
public:
	S(int x, int y) : Figure(x, y) { };
	void drawFigure(int matrix[33][10]);
	void clearFigure(int matrix[33][10]);
	void rotateFigure(int matrix[33][10]);
	bool checkRight(int matrix[33][10]);
	bool checkLeft(int matrix[33][10]);
	bool checkBottom(int matrix[33][10]);

	~S();
};
class T :
	public Figure
{
public:
	T(int x, int y) : Figure(x, y) { };
	void drawFigure(int matrix[33][10]);
	void clearFigure(int matrix[33][10]);
	void rotateFigure(int matrix[33][10]);
	bool checkRight(int matrix[33][10]);
	bool checkLeft(int matrix[33][10]);
	bool checkBottom(int matrix[33][10]);

	~T();
};
class L :
	public Figure
{
public:
	L(int x, int y) : Figure(x, y) { };
	void drawFigure(int matrix[33][10]);
	void clearFigure(int matrix[33][10]);
	void rotateFigure(int matrix[33][10]);
	bool checkRight(int matrix[33][10]);
	bool checkLeft(int matrix[33][10]);
	bool checkBottom(int matrix[33][10]);

	~L();
};
class Z :
  public Figure
{
public:
  Z(int x, int y) : Figure(x, y) { };
  void drawFigure(int matrix[33][10]);
  void clearFigure(int matrix[33][10]);
  void rotateFigure(int matrix[33][10]);
  bool checkRight(int matrix[33][10]);
  bool checkLeft(int matrix[33][10]);
  bool checkBottom(int matrix[33][10]);

  ~Z();
};


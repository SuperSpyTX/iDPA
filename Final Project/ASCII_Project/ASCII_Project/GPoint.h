
class GPoint
{
public:
	// Fields
	int x, y, move;
	char character;
	bool needCalc;
	int uqid;

	// Constructors
	GPoint();
	GPoint(int nx, int ny, char ncharacter);
	~GPoint();
};


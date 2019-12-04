//точка в трёхмерном пространстве 
class point
{
public:
	double x;
	double y;
	double z;
	double p;
	int i;
	bool operator ==(const point& M)
	{
		if (x == M.x && y == M.y && z == M.z)return true;
		return false;
	}
	point operator +(const point& M)
	{
		point R;
		R.x = x + M.x;
		R.y = y + M.y;
		R.z = z + M.z;
		return R;
	}
	point operator -(const point& M)
	{
		point R;
		R.x = x - M.x;
		R.y = y - M.y;
		R.z = z - M.z;
		return R;
	}
};
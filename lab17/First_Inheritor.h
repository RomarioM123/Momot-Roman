#include "BaseClass.h"
class CMalware final : public CProgram
{
private:
	string type;

public:
	string getInfo() const override;
	stringstream getStr() const override final;
	
	template<typename T>
	void serialize(T& serialize)
	{
		serialize(cereal::base_class<CProgram>(this));
		serialize(cereal::make_nvp("Type of malware", type));
	}

	CMalware();
	CMalware(string, int, int, int, int, string);
	CMalware(const CMalware&);
	~CMalware() override;
};
#ifndef FACADEINFO_H
#define FACADEINFO_H
#include <QString>




class abstrFacadeInfo
{
public:

   virtual void setTime(const QString& t)=0;
   virtual void setName(const QString& n)=0;
   virtual void setResult(const QString& s)=0;
   virtual void setCounter(uint32_t c)=0;

    virtual QString getTime() const =0;
    virtual QString getName() const =0;
    virtual QString getResult() const =0;
    virtual uint32_t getCounter() const =0;
   virtual ~abstrFacadeInfo()=default;

};

class concreteFacadeInfo:public abstrFacadeInfo
{
public:

    concreteFacadeInfo() = default;
    concreteFacadeInfo(const QString& time, const QString& name, const QString& result, uint32_t counter);
    void setTime(const QString& t) override;
    void setName(const QString& n)override;
    void setResult(const QString& s)override;
    void setCounter(uint32_t c) override;


    virtual QString getTime() const override;
    virtual QString getName() const override;
    virtual QString getResult() const override;
    virtual uint32_t getCounter() const override;

    private:
        QString time="";
        QString name="";
        QString result="";
        uint32_t counter=0;



};



#endif // FACADEINFO_H

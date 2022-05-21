#ifndef FACADEINFO_H
#define FACADEINFO_H
#include <QString>




class abstrFacadeInfo
{
public:

   virtual void setTime(qint64 t)=0;
   virtual void setName(QString n)=0;
   virtual void setResult(QString s)=0;
   virtual void setCounter(uint32_t c)=0;

    virtual qint64 getTime() const =0;
    virtual QString getName() const =0;
    virtual QString getResult() const =0;
    virtual uint32_t getCounter() const =0;
   virtual ~abstrFacadeInfo()=default;

};

class concreteFacadeInfo:public abstrFacadeInfo
{
public:

    concreteFacadeInfo() = default;
    void setTime(qint64 t) override;
    void setName(QString n)override;
    void setResult(QString s)override;
    void setCounter(uint32_t c) override;


    virtual qint64 getTime() const override;
    virtual QString getName() const override;
    virtual QString getResult() const override;
    virtual uint32_t getCounter() const override;

    private:
        qint64 time=0;
        QString name="";
        QString result="";
        uint32_t counter=0;



};



#endif // FACADEINFO_H

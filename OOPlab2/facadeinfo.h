#ifndef FACADEINFO_H
#define FACADEINFO_H
#include <QString>




class abstrFacadeInfo
{
public:

   virtual void setTime(qint64 t)=0;
   virtual void setName(QString n)=0;
   virtual void setResult(QString s)=0;
   virtual ~abstrFacadeInfo()=default;

};
template<typename T>
class concreteFacadeInfo:public abstrFacadeInfo
{
public:

    concreteFacadeInfo() = default;
    void setTime(qint64 t) override;
    void setName(QString n)override;
    void setResult(QString s)override;
    private:
        qint64 time=0;
        QString name="";
        QString result="";
        uint32_t counter;
        //saved vector
        std::vector<T> vec;
        //id of the first successful string matching
        int firstMatching;


};



#endif // FACADEINFO_H

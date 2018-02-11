#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <QList>
#include <QStack>
#include <QQueue>
#include <QMap>
#include <QSet>
#include <QMultiMap>
#include <QMultiHash>



class Person
{
public:
Person( const QString& name, const QString& number ):
    m_name(name), m_number(number){}



const QString& name() const{
    return m_name;
}
const QString& number() const{
    return m_number;
}

private:
QString m_name, m_number;

};



bool operator==( const Person &a, const Person &b )
{
return (a.name() == b.name()) && (a.number() == b.number());
}
uint qHash( const Person &key )
{
return qHash( key.name() ) ^ qHash( key.number() );
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);


    QMultiHash<QString, int> multi;

    multi.insert("foo", 10);
    multi.insert("foo", 20);
    multi.insert("bar", 30);

    QSet<QString> keys = QSet<QString>::fromList(multi.keys());
    foreach (QString key, keys)
        foreach(int value, multi.values(key))
            qDebug() << key << " : " << value;

    QMultiHash<QString, int>::ConstIterator i = multi.find("foo");
    while(i != multi.end() && i.key() == "foo"){
        qDebug() << i.value();
        ++i;
    }


















//    QMultiMap<QString, int> multi;
//    multi.insert("foo", 10);
//    multi.insert("foo", 20);
//    multi.insert("bar", 30);

    /*QSet<QString> keys = QSet<QString>::fromList(multi.keys());
    foreach (QString key, keys)
        foreach (int value, multi.values(key))
            qDebug() << key << " : " << value;*/

//    QMultiMap<QString , int>::ConstIterator i = multi.find("foo");
//    while(i != multi.end() && i.key() == "foo"){
//        qDebug() << i.value();
//        ++i;
//    }




























//    QHash<Person, int> hash;
//    hash[ Person( "Anders", "8447070" ) ] = 10;
//    hash[ Person( "Micke", "7728433" ) ] = 20;


//    qDebug() << hash.value( Person( "Anders", "8447070" ) ); // 10
//    qDebug() << hash.value( Person( "Anders", "8447071" ) ); // 0
//    qDebug() << hash.value( Person( "Micke", "7728433" ) ); // 20
//    qDebug() << hash.value( Person( "Michael", "7728433" ) ); // 0

//    QSet<QString>set;
//    set << "Ada" << "C++" << "Ruby";

//    for(QSet<QString>::Iterator i = set.begin(); i != set.end(); ++i)
//        qDebug()<< *i;

//    if(set.contains("FORTRAN"))
//        qDebug() << "FORTRAN IS IN THE SET";
//    else
//        qDebug() << "FORTRAN IS NOT IN THE SET";








    return app.exec();
}


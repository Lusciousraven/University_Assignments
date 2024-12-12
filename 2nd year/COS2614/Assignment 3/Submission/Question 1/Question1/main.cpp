#include <QCoreApplication>
#include <QString>
#include <QVector>
#include <QDateTime>
#include <QDebug>
#include <QMap>



class Transaction {
protected:
  QString m_Type;
  QDateTime m_DateTime;

public:
  Transaction(QString type, QDateTime dateTime) {
    m_Type = type;
    m_DateTime = dateTime;
  }

  QString getType() {
    return m_Type;
  }

  QDateTime getDateTime() {
    return m_DateTime;
  }


  QString toString() {
    return m_Type + " transaction on " + m_DateTime.toString();
    }

  virtual double computeCost() = 0;
};


class Deposit : public Transaction {
private:
   double m_Amount;
    double m_Fee = 5.0;

public:
  Deposit(double amount, QDateTime dateTime) : Transaction("Deposit", dateTime) {
    m_Amount = amount;
  }

  double computeCost() override {
    return m_Fee;
  }

  QString toString()  {
    return Transaction::toString() + ", Deposited Amount:" + QString::number(m_Amount)
           + ", Fee: " + QString::number(m_Fee);
  }
};


class Withdrawal : public Transaction {
private:
   double m_Amount;
   double m_Percentage = 0.09;

public:

   double m_Fee;

   Withdrawal(double amount, QDateTime dateTime) : Transaction("Withdrawal", dateTime)
   {
    m_Amount = amount;
   }

   double computeCost() override
   {

    m_Fee = m_Amount * m_Percentage;
    return m_Fee;
   }

   QString toString()
   {
    return Transaction::toString() +  ",Withdrawal Amount:" + QString::number(m_Amount)
           + ",Fee: " + QString::number(m_Fee);
   }
};


class BalanceEnquiry : public Transaction {
private:
   QDate m_FromDate;
   QDate m_ToDate;

public:

   BalanceEnquiry(QDate fDate, QDate tDate, QDateTime dateTime) : Transaction("Balance Enquiry", dateTime)
   {
    m_FromDate = fDate;
    m_ToDate = tDate;
   }

  double computeCost() override {
    return 0.0;
  }

  QString toString()
  {
    return Transaction::toString() + ", Transactions from: " + m_FromDate.toString("yyyy-MM-dd") + " to " + m_ToDate.toString("yyyy-MM-dd");
  }
};




class SavingsAccount {
private:
  QString m_CustomerName;
  QString m_AccountNumber;
  QList<Transaction*> m_TransactionList;

public:
  SavingsAccount(QString name, QString num) {
    m_CustomerName = name;
    m_AccountNumber = num;
  }

  void addTransaction(Transaction* t) {
    m_TransactionList.push_back(t);
  }

  double totalTransactionCost() {
    double total = 0.0;
    for(int i=0; i<m_TransactionList.size(); ++i) {
      total += m_TransactionList[i]->computeCost();
    }
    return total;
  }

  void extracted(QMap<QString, int> &counts, int &maxCount, QString &maxType) {
    for (QString type : counts.keys()) {
      if (counts[type] > maxCount) {
          maxCount = counts[type];
          maxType = type;
      }
    }
  }
  QString frequentTransactionType() {
    QMap<QString, int> counts;
    for(int i=0; i<m_TransactionList.size(); ++i) {
      QString type = m_TransactionList[i]->getType();
      if(counts.contains(type)) {
          counts[type]++;
      } else {
          counts[type] = 1;
      }
    }
    int maxCount = 0;
    QString maxType;
    extracted(counts, maxCount, maxType);

    return maxType;
  }

  QList<Transaction*> transactionsOnADate(QDate date) {
    QList<Transaction*> result;
    for(int i=0; i<m_TransactionList.size(); ++i) {
      if(m_TransactionList[i]->getDateTime().date() == date) {
          result.push_back(m_TransactionList[i]);
      }
    }
    return result;
  }

  QString toString() {
    QString str = "Savings Account\n";
    str += "Name: " + m_CustomerName + "\n";
    str += "Account Number: " + m_AccountNumber + "\n";
    str += "Transactions:\n";
    for(int i=0; i<m_TransactionList.size(); ++i) {
      str += m_TransactionList[i]->toString() + "\n";
    }
    return str;
  }
};

int main(int argc, char *argv[]) {
  QCoreApplication app(argc, argv);

  QDateTime date1 = QDateTime::currentDateTime();
  QDateTime date2 = date1.addDays(1);
  QDateTime date3 = date2.addDays(1);
  QDateTime date4 = date3.addDays(1);
  QDateTime date5 = date4.addDays(1);
  QDateTime date6 = date5.addDays(1);
  QDate date8;
  date8= QDate(2023,8,15);
  QDate date9;
  date9= QDate(2023,8,17);
  QDate date10;
  date10= QDate(2023,8,12);
  QDate date11;
  date11= QDate(2023,8,16);

  SavingsAccount account("Ant March", "1234567890");
  account.addTransaction(new Deposit(500.0, date1));
  account.addTransaction(new Deposit(300.0, date2));
  account.addTransaction(new Withdrawal(100.0, date3));
  account.addTransaction(new Withdrawal(200.0, date4));
  account.addTransaction(new BalanceEnquiry(date8,date9,date5));
  account.addTransaction(new BalanceEnquiry(date10,date11,date6));

  qDebug() << "Frequent transaction: " << account.frequentTransactionType();
  QDate date = QDate::currentDate();
  qDebug() << "Transactions on " << date << ":" << account.transactionsOnADate(date);
  qDebug() << account.toString();
  qDebug() << "Total transaction cost:" << account.totalTransactionCost();

  return app.exec();
}



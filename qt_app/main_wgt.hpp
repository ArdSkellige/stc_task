#ifndef MAINWGT_H
#define MAINWGT_H

#include <QComboBox>
#include <QFile>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>

#include "employee.hpp"

class MainWgt_t : public QWidget
{
	Q_OBJECT
private:
	std::vector<Employee_t> vecEmpl;
protected:
// Frame for Adjust:
	QPushButton *btnAddEmployeeP;
	QLabel *labelAdjustP;
	QFrame *frameAdjustP;
	QVBoxLayout *frameAdjustLayoutP;
// layout 1:
	// layout 1.1:
	QLabel* lblNameP;
	QLineEdit* ledNameP;
	// layout 1.2:
	QLabel* lblSurnameP;
	QLineEdit* ledSurnameP;
	// layout 1.3:
	QLabel* lblMiddleNameP;
	QLineEdit* ledMiddleNameP;
// layout 2:
	QLabel* lblSexP;
	QComboBox* cmbboxSexP;
	QLabel* lblAgeP;
	QSpinBox* spnbAgeP;
	QLabel* lblExperienceP;
	QSpinBox* spnbExperienceP;
// layout 3:
	QLabel* lblPhoneNumberP;
	QLineEdit* ledPhoneNumberP;
// layout 4:
	QLabel* lblFindEmplP;
	QLineEdit* ledFindEmplP;
	QPushButton* btbFindEmplP;
	QLabel* lblQuantityEmplP;
	QLabel* lblQuantityEmplModeP;
// layout 5:
	QGroupBox *grbxBtnPnlP;
	QPushButton* btnWriteFileP;
	QPushButton* btnCheckFileP;

public:
	MainWgt_t(QWidget* parent = nullptr);
	~MainWgt_t();

	QLabel* createQLabel(const char *str = "");
	QLabel* createNameQLabel(const char *str = "");
	QComboBox* createQComboBox();
	QPushButton* createPushButton(const char* str = "");
	QLineEdit* createQLineEdit();

public slots:
	void slotAddEmployee();
	void slotFindEmployee();
	void slotCheckID(QString id);
	void slotWritefile();
};
#endif // MAINWGT_H
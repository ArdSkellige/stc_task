#include "main_wgt.hpp"

MainWgt_t::MainWgt_t(QWidget* parent) : QWidget(parent)
{
	setWindowTitle("List of employees");
	this->setMinimumSize(450, 300);
	
	// create Main layout:
	auto* vblayMainP = new QVBoxLayout(this);

	{// create QFrame for Adjust:
		frameAdjustP = new QFrame(this);
		frameAdjustP->setFrameStyle(QFrame::Sunken | QFrame::Box);
		frameAdjustP->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
		{// create main layout for QFrame:
			frameAdjustLayoutP = new QVBoxLayout(frameAdjustP);
			{
				auto* hblayP = new QHBoxLayout(this);
				labelAdjustP = createQLabel(" Employee Card ");
				labelAdjustP->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
				// labelAdjustP->setFrameStyle(QFrame::Sunken | QFrame::Box);
				labelAdjustP->setAlignment(Qt::AlignLeft);

				hblayP->addWidget(labelAdjustP, Qt::AlignLeft);
				frameAdjustLayoutP->addLayout(hblayP);
			}
			vblayMainP->addWidget(frameAdjustP);
		}
	}
	{// layout 1:
		auto* vblayP = new QVBoxLayout(this);
		{// layout 1.1:
			auto* hblayP = new QHBoxLayout(this);
			lblNameP = createNameQLabel("Name");
			ledNameP = new QLineEdit;

			hblayP->addWidget(lblNameP);
			hblayP->addWidget(ledNameP);
			vblayP->addLayout(hblayP);
		}
		{// layout 1.2:
			auto* hblayP = new QHBoxLayout(this);
			lblSurnameP = createNameQLabel("Surame");
			ledSurnameP = new QLineEdit;

			hblayP->addWidget(lblSurnameP);
			hblayP->addWidget(ledSurnameP);
			vblayP->addLayout(hblayP);
		}
		{// layout 1.3:
			auto* hblayP = new QHBoxLayout(this);
			lblMiddleNameP = createNameQLabel("Middle Name");
			ledMiddleNameP = new QLineEdit;
			
			hblayP->addWidget(lblMiddleNameP);
			hblayP->addWidget(ledMiddleNameP);
			vblayP->addLayout(hblayP);
		}
		frameAdjustLayoutP->addLayout(vblayP);
	}
	{// layout 2:
		auto* hblayP = new QHBoxLayout(this);
		lblSexP = createQLabel("Sex");
		cmbboxSexP = createQComboBox();
		lblAgeP = createQLabel("Age");
		spnbAgeP = new QSpinBox();
		spnbAgeP->setRange(14, 70);
		lblExperienceP = createQLabel("Work Experience");
		spnbExperienceP = new QSpinBox();
		spnbExperienceP->setRange(0, 50);
		
		hblayP->addWidget(lblSexP);
		hblayP->addWidget(cmbboxSexP);
		hblayP->addWidget(lblAgeP);
		hblayP->addWidget(spnbAgeP);
		hblayP->addWidget(lblExperienceP);
		hblayP->addWidget(spnbExperienceP);
		frameAdjustLayoutP->addLayout(hblayP);
	}
	{// layout 3:
		auto* hblayP = new QHBoxLayout(this);
		lblPhoneNumberP = createQLabel("Phone Number");
		ledPhoneNumberP = new QLineEdit();

		hblayP->addWidget(lblPhoneNumberP);
		hblayP->addWidget(ledPhoneNumberP);
		frameAdjustLayoutP->addLayout(hblayP);
	}
	{// layout 4:
		auto* hblayP = new QHBoxLayout(this);
		lblFindEmplP = createQLabel("Employee ID:");
		ledFindEmplP = createQLineEdit();
		btbFindEmplP = createPushButton("Find ID");

		hblayP->addWidget(lblFindEmplP);
		hblayP->addWidget(ledFindEmplP);
		hblayP->addWidget(btbFindEmplP);
		frameAdjustLayoutP->addLayout(hblayP);
	}
	{// layout 5:
		auto* hblayP = new QHBoxLayout(this);
		btnAddEmployeeP = createPushButton(" Add Employee ");
		btnAddEmployeeP->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
		btnDeleteEmployeeP = createPushButton(" Delete Employee ");
		btnDeleteEmployeeP->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
		lblQuantityEmplP = createQLabel("Quantity Empls:");
		lblQuantityEmplModeP = createQLabel("0");

		hblayP->addWidget(btnAddEmployeeP);
		hblayP->addWidget(btnDeleteEmployeeP);
		hblayP->addWidget(lblQuantityEmplP);
		hblayP->addWidget(lblQuantityEmplModeP);
		hblayP->setAlignment(Qt::AlignLeft);
		frameAdjustLayoutP->addLayout(hblayP);
	}
	{// layout 6:
		auto* vblayP = new QVBoxLayout(this);
		grbxBtnPnlP = new QGroupBox("File");
		btnWriteFileP = createPushButton("Write");
		btnWriteAndModifyFileP = createPushButton("Write and Modify");
		btnCheckFileP = createPushButton("Check");

		vblayP->addWidget(btnWriteFileP);
		vblayP->addWidget(btnWriteAndModifyFileP);
		vblayP->addWidget(btnCheckFileP);
		grbxBtnPnlP->setLayout(vblayP);
		vblayMainP->addWidget(grbxBtnPnlP);

		{// layout 6.1:
			auto* hblayP = new QHBoxLayout(this);
			lblCrcP = createQLabel("Current crc");
			lblCrcModeP = createQLabel(" - ");
			lblCrcModeP->setFixedWidth(35);
			lblCrcModeP->setFrameStyle(QFrame::Sunken | QFrame::Box);
			lblInputRangeP = createQLabel("Input number (0...255):");
			ledInputRangeP = createQLineEdit();

			hblayP->addWidget(lblCrcP);
			hblayP->addWidget(lblCrcModeP);
			hblayP->addWidget(lblInputRangeP);
			hblayP->addWidget(ledInputRangeP);
			vblayP->addLayout(hblayP);
		}
	}
	vblayMainP->addStretch();

	connect(btnAddEmployeeP, &QPushButton::clicked, this, &MainWgt_t::slotAddEmployee);
	connect(btnDeleteEmployeeP, &QPushButton::clicked, this, &MainWgt_t::slotDeleteEmployee);
	connect(btbFindEmplP, &QPushButton::clicked, this, &MainWgt_t::slotFindEmployee);
	connect(ledFindEmplP, &QLineEdit::textChanged, this, &MainWgt_t::slotCheckID);
	connect(ledInputRangeP, &QLineEdit::textChanged, this, &MainWgt_t::slotCheckRange);
	connect(btnWriteFileP, &QPushButton::clicked, this, &MainWgt_t::slotWritefile);
	connect(btnWriteAndModifyFileP, &QPushButton::clicked, this, &MainWgt_t::slotWriteModifyFile);
}

MainWgt_t::~MainWgt_t()
{
}

QLabel* MainWgt_t::createQLabel(const char *str)
{
	QLabel* labelP = new QLabel(str);
	labelP->setAlignment(Qt::AlignCenter);
	labelP->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
	return labelP;
}

QLabel* MainWgt_t::createNameQLabel(const char *str)
{
	QLabel* labelP = new QLabel(str);
	labelP->setAlignment(Qt::AlignCenter);
	labelP->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
	labelP->setMinimumWidth(90);
	labelP->setFrameStyle(QFrame::Sunken | QFrame::Box);
	return labelP;
}

QComboBox* MainWgt_t::createQComboBox()
{
	QComboBox* tmpP = new QComboBox;
	tmpP->addItem("Man");
	tmpP->addItem("Woman");
	return tmpP;
}

QPushButton* MainWgt_t::createPushButton(const char* str)
{
	QPushButton* btnTmpP = new QPushButton(str);
	btnTmpP->setStyleSheet("background-color: Gainsboro");
	return btnTmpP;
}

QLineEdit* MainWgt_t::createQLineEdit()
{
	QLineEdit* tmpLEd = new QLineEdit();
	QIntValidator* valid = new QIntValidator(0, 255);
	tmpLEd->setValidator(valid);
	return tmpLEd;
}

void MainWgt_t::slotAddEmployee()
{
	Employee_t tmpEmp;
	tmpEmp.SetName(ledNameP->text().toStdString().c_str());
	tmpEmp.SetSurname(ledSurnameP->text().toStdString().c_str());
	tmpEmp.SetMiddlename(ledMiddleNameP->text().toStdString().c_str());
	tmpEmp.SetSex(cmbboxSexP->currentIndex());
	tmpEmp.SetAge(spnbAgeP->value());
	tmpEmp.SetExperience(spnbExperienceP->value());
	tmpEmp.SetPhoneNumber(ledPhoneNumberP->text().toStdString().c_str());

	vecEmpl.push_back(tmpEmp);
	lblQuantityEmplModeP->setText(QString::number(vecEmpl.size()));
}

void MainWgt_t::slotDeleteEmployee()
{
	QVariant variant(ledFindEmplP->text());
	int num = variant.toInt();
	if(num < vecEmpl.size())
	{
		auto itbeg = vecEmpl.begin();
		itbeg += num;
		vecEmpl.erase(itbeg);

		lblQuantityEmplModeP->setText(QString::number(vecEmpl.size()));
	}
}

void MainWgt_t::slotFindEmployee()
{
	QVariant variant(ledFindEmplP->text());
	int num = variant.toInt();
	if(num >= vecEmpl.size())
	{
		num = vecEmpl.size() - 1;
	}
	
	ledNameP->setText(vecEmpl[num].GetName());
	ledSurnameP->setText(vecEmpl[num].GetSername());
	ledMiddleNameP->setText(vecEmpl[num].GetMiddlename());
	cmbboxSexP->setCurrentIndex(vecEmpl[num].GetSex());
	spnbAgeP->setValue(vecEmpl[num].GetAge());
	spnbExperienceP->setValue(vecEmpl[num].GetExperience());
	ledPhoneNumberP->setText(vecEmpl[num].GetPhoneNumber());
}

void MainWgt_t::slotCheckID(QString id)
{
	QVariant variant(id);
	int num = variant.toInt();
	if(num >= vecEmpl.size())
	{
		if(vecEmpl.size())
		{
			num = vecEmpl.size() - 1;
		}
		else if(vecEmpl.size() == 0)
		{
			num = 0;
		}
		ledFindEmplP->setText(QString::number(num));
	}
}

void MainWgt_t::slotCheckRange(QString id)
{
	QVariant variant(id);
	int num = variant.toInt();
	if(num > 255)
	{
		num = 255;
		ledInputRangeP->setText(QString::number(num));
	}
}

void MainWgt_t::slotWritefile()
{
	QFile file("employee list.txt");
	if(file.open(QIODevice::ReadWrite))
	{
		file.resize(0);
		QTextStream txtstr(&file);
		for(size_t i = 0; i < vecEmpl.size(); i++)
		{
			txtstr << "ID: " << i << ", Name: " << vecEmpl[i].GetName() << ", Surame: " << vecEmpl[i].GetSername() << ", Middlename: " << vecEmpl[i].GetMiddlename() << ",\n";
			txtstr << " Age = " << vecEmpl[i].GetAge() << ", Sex = " << vecEmpl[i].GetSex();
			txtstr << ", Experience = " << vecEmpl[i].GetExperience() << ", PhoneNumber " << vecEmpl[i].GetPhoneNumber() << ";\n";
		}
	}
	file.close();
}

void MainWgt_t::slotWriteModifyFile()
{
	QByteArray bAr;
	for(size_t i = 0; i < vecEmpl.size(); i++)
	{
		bAr.append(vecEmpl[i].GetName()).append(" ");
		bAr.append(vecEmpl[i].GetSername()).append(" ");
		bAr.append(vecEmpl[i].GetMiddlename()).append(" ");
		bAr.append(QString::number(vecEmpl[i].GetAge()).toStdString().c_str()).append(" ");
		bAr.append(QString::number(vecEmpl[i].GetSex()).toStdString().c_str()).append(" ");
		bAr.append(QString::number(vecEmpl[i].GetExperience()).toStdString().c_str()).append(" ");
		bAr.append(vecEmpl[i].GetPhoneNumber()).append("\n");
	}

	QVariant variant(ledInputRangeP->text());
	uint8_t mask = variant.toInt();
	for(size_t i = 0; i < bAr.size(); i++)
	{
		bAr[i] = bAr[i] ^ mask;
	}

	QFile file(QFileDialog::getSaveFileName(this, "Name file", "byteArray_list", "*.txt;; *.bin"));
	if(file.open(QIODevice::ReadWrite))
	{
		file.resize(0);
		file.write(bAr);
	}

	// QString fileCrcName = file.fileName();
	// for(size_t i = 0; i < 3; i++)
	// {
	// 	fileCrcName.removeLast();
	// }
	// QFile fileCrc(fileCrcName + "crc");
	// if(fileCrc.open(QIODevice::ReadWrite))
	// {
	// 	fileCrc.resize(0);
	// 	fileCrc.write("114");
	// }

	file.close();
	// fileCrc.close();
}
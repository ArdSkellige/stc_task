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
				btnAddEmployeeP = createPushButton(" Add Employee ");
				btnAddEmployeeP->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);

				hblayP->addWidget(labelAdjustP, Qt::AlignLeft);
				hblayP->addWidget(btnAddEmployeeP, Qt::AlignRight);
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
		auto* vblayP = new QVBoxLayout(this);
		grbxBtnPnlP = new QGroupBox("File");
		btnWriteFileP = createPushButton("Write");
		btnCheckFileP = createPushButton("Check");

		vblayP->addWidget(btnWriteFileP);
		vblayP->addWidget(btnCheckFileP);
		grbxBtnPnlP->setLayout(vblayP);
		vblayMainP->addWidget(grbxBtnPnlP);
	}
	vblayMainP->addStretch();

	connect(btnAddEmployeeP, &QPushButton::clicked, this, &MainWgt_t::slotAddEmployee);
	// connect(cmbboxFileMaskP, &QComboBox::activated, myLineEditP, &MyLineEdit::slotFileMode);
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
}
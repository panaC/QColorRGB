/* Qextinction / dialog.cpp
   Copyright (C) 2012 Pierre Leroux

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("QColor Slider RGB - Pierre Leroux - 01/2012");
    setWindowFlags(Qt::WindowCloseButtonHint);
    setWindowIcon(QIcon("color_settings.png"));

    m_fond = new QHBoxLayout();

    m_choixCouleurFond = new QColor(0,0,0);
    m_fondCouleur = new QPixmap(300, 300);
    m_fondCouleur->fill(*m_choixCouleurFond);

    QGroupBox *fondCouleur = new QGroupBox("Couleur", this);
    QVBoxLayout *layoutCouleur = new QVBoxLayout();
    m_couleur = new QLabel(this);
    m_couleur->setPixmap(*m_fondCouleur);
    m_couleur->setCursor(QCursor(Qt::CrossCursor));
    m_infosCouleur = new QLabel(this);
    m_infosCouleur->setAlignment(Qt::AlignCenter);
    layoutCouleur->addWidget(m_couleur);
    layoutCouleur->addWidget(m_infosCouleur);
    fondCouleur->setLayout(layoutCouleur);


    QGroupBox *fondSlider = new QGroupBox("Slider", this);
    QHBoxLayout *layoutSlider = new QHBoxLayout();

    QVBoxLayout *layoutSRouge = new QVBoxLayout();
    m_SRouge = new QSlider(Qt::Vertical, this);
    m_SRouge->setRange(0, 255);
    m_SRouge->setCursor(QCursor(Qt::SizeVerCursor));
    connect(m_SRouge, SIGNAL(sliderMoved(int)), this, SLOT(actualisationCouleur(int)));
    connect(m_SRouge, SIGNAL(valueChanged(int)), this, SLOT(actualisationCouleur(int)));
    QLabel *rouge = new QLabel(" Rouge", this);
    layoutSRouge->addWidget(m_SRouge);
    layoutSRouge->addWidget(rouge);

    QVBoxLayout *layoutSBleu = new QVBoxLayout();
    m_SBleu = new QSlider(Qt::Vertical, this);
    m_SBleu->setRange(0, 255);
    m_SBleu->setCursor(QCursor(Qt::SizeVerCursor));
    connect(m_SBleu, SIGNAL(sliderMoved(int)), this, SLOT(actualisationCouleur(int)));
    connect(m_SBleu, SIGNAL(valueChanged(int)), this, SLOT(actualisationCouleur(int)));
    QLabel *bleu = new QLabel("  Bleu ", this);
    layoutSBleu->addWidget(m_SBleu);
    layoutSBleu->addWidget(bleu);

    QVBoxLayout *layoutSVert = new QVBoxLayout();
    m_SVert = new QSlider(Qt::Vertical, this);
    m_SVert->setRange(0, 255);
    m_SVert->setCursor(QCursor(Qt::SizeVerCursor));
    connect(m_SVert, SIGNAL(sliderMoved(int)), this, SLOT(actualisationCouleur(int)));
    connect(m_SVert, SIGNAL(valueChanged(int)), this, SLOT(actualisationCouleur(int)));
    QLabel *vert = new QLabel("  Vert ", this);
    layoutSVert->addWidget(m_SVert);
    layoutSVert->addWidget(vert);

    layoutSlider->addLayout(layoutSRouge);
    layoutSlider->addLayout(layoutSBleu);
    layoutSlider->addLayout(layoutSVert);
    fondSlider->setLayout(layoutSlider);

    QHBoxLayout *layoutBouton = new QHBoxLayout();
    m_choixAffichage = new QComboBox(this);
    m_choixAffichage->addItem("Affichage Pourcentage");
    m_choixAffichage->addItem("Affichage /255");
    m_choixAffichage->addItem("Affichage /1000");
    connect(m_choixAffichage, SIGNAL(activated(int)), this, SLOT(actualisationCouleur()));
    m_about = new QPushButton("A propos", this);
    connect(m_about, SIGNAL(clicked()), this, SLOT(ouvrirAbout()));
    QPushButton *Quitter = new QPushButton("Quitter", this);
    connect(Quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    layoutBouton->addWidget(m_choixAffichage);
    layoutBouton->addStretch();
    layoutBouton->addWidget(m_about);
    layoutBouton->addWidget(Quitter);

    m_fond->addStretch();
    m_fond->addWidget(fondCouleur);
    m_fond->addWidget(fondSlider);
    m_fond->addStretch();

    QVBoxLayout *fondFenetre = new QVBoxLayout();
    fondFenetre->addStretch();
    fondFenetre->addLayout(m_fond);
    fondFenetre->addStretch();

    QVBoxLayout *fondFenetre2 = new QVBoxLayout();
    fondFenetre2->addLayout(fondFenetre);
    fondFenetre2->addLayout(layoutBouton);

    setLayout(fondFenetre2);

}

void Dialog::ouvrirAbout()
{
    QDialog *APropos = new QDialog(this, Qt::WindowCloseButtonHint);
    APropos->setFixedSize(300, 200);
    APropos->setWindowTitle("A Propos de QColor Slider RGB");

    QTabWidget *tab = new QTabWidget(APropos);      //QTABWIDGET incluant un QLabel et deux QTextEdit
    tab->setGeometry(5, 5, 290, 190);

    QLabel *infos = new QLabel(APropos);
    infos->setTextFormat(Qt::RichText); //format texte RTF
    infos->setText("<P><h3>QColor Slider RGB</h3></p><p>Créer par Pierre Leroux</p><p>Compilé le 12/01/2012<p><p>Version 1.0</p>");
    infos->setAlignment(Qt::AlignCenter);

    QTextEdit *Alire = new QTextEdit(APropos);
    Alire->setText("Ce programme est fournit « EN L'ÉTAT », SANS GARANTIE D'AUCUNE SORTE, INCLUANT, SANS S'Y LIMITER, LES GARANTIES D'ABSENCE DE DÉFAUT, DE QUALITÉ MARCHANDE, D'ADÉQUATION À UN USAGE PARTICULIER.");
    Alire->setReadOnly(true);

    QTextEdit *licence = new QTextEdit(APropos);
    licence->setText("<p>This program is free software: you can redistribute it and/or modify"
                     "it under the terms of the GNU General Public License as published by"
                     "the Free Software Foundation, either version 3 of the License, or"
                     "(at your option) any later version."
                     "This program is distributed in the hope that it will be useful,"
                     "but WITHOUT ANY WARRANTY; without even the implied warranty of"
                     "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the"
                     "GNU General Public License for more details."
                     "You should have received a copy of the GNU General Public License"
                     "along with this program. If not, see http://www.gnu.org/licenses/.</p>");

    licence->setReadOnly(true);

    tab->addTab(infos, "Information");
    tab->addTab(Alire, "A lire");
    tab->addTab(licence, "GNU General Public License");

    APropos->exec();    //ouverture de la fenetre
}

void Dialog::actualisationCouleur(int valeurRGB)
{
    static double rouge = 0;
    static double bleu = 0;
    static double vert = 0;

    QString texte, SRouge, SBleu, SVert;

    QSlider *slider = qobject_cast<QSlider *>(sender());

    if(slider == m_SRouge)
    {
        m_choixCouleurFond->setRed(valeurRGB);
        rouge = valeurRGB;
    }
    else if(slider == m_SBleu)
    {
        m_choixCouleurFond->setBlue(valeurRGB);
        bleu = valeurRGB;
    }
    else if(slider == m_SVert)
    {
        m_choixCouleurFond->setGreen(valeurRGB);
        vert = valeurRGB;
    }

    switch(isAffichage())
    {
    case Dialog::pourcentage:
        texte = "Rouge = " + SRouge.setNum(isPourcentage(rouge)) + "%, Bleu = " + SBleu.setNum(isPourcentage(bleu)) + "%, Vert = " + SVert.setNum(isPourcentage(vert)) + "%";
        break;
    case Dialog::pour255:
        texte = "Rouge = " + SRouge.setNum(rouge) + ", Bleu = " + SBleu.setNum(bleu) + ", Vert = " + SVert.setNum(vert) + " /255";
        break;
    case Dialog::pour1000:
        texte = "Rouge = " + SRouge.setNum(isPour1000(rouge)) + ", Bleu = " + SBleu.setNum(isPour1000(bleu)) + ", Vert = " + SVert.setNum(isPour1000(vert)) + " /1000";
        break;
    }

    m_infosCouleur->setText(texte);

    m_couleur->setToolTip(texte);

    m_fondCouleur->fill(*m_choixCouleurFond);
    m_couleur->setPixmap(*m_fondCouleur);
}

Dialog::affichage Dialog::isAffichage()
{
    if(m_choixAffichage->currentText() == "Affichage Pourcentage")
    {
        return Dialog::pourcentage;
    }
    else if(m_choixAffichage->currentText() == "Affichage /255")
    {
        return Dialog::pour255;
    }
    else
    {
        return Dialog::pour1000;
    }
}

double Dialog::isPourcentage(double valeur)
{
    double val(0);
    val = valeur / 255;
    val = val * 100;
    return val;
}

double Dialog::isPour1000(double valeur)
{
    double val(0);
    val = valeur / 255;
    val = val * 1000;
    return val;
}

Dialog::~Dialog()
{
    
}

/* Qextinction / dialog.h
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

#ifndef DIALOG_H
#define DIALOG_H

#include <QApplication>
#include <QIcon>
#include <QCursor>
#include <QtGui/QDialog>
#include <QtGui/QSlider>
#include <QtGui/QLabel>
#include <QtGui/QComboBox>
#include <QtGui/QPushButton>
#include <QtGui/QPixmap>
#include <QtGui/QColor>
#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QTimer>
#include <QString>

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

public slots:
    void actualisationCouleur(int valeurRGB = 0);
    void ouvrirAbout();

private:

    QHBoxLayout *m_fond;
    QLabel *m_couleur;
    QLabel *m_infosCouleur;
    QSlider *m_SRouge;
    QSlider *m_SBleu;
    QSlider *m_SVert;
    QPixmap *m_fondCouleur;
    QColor *m_choixCouleurFond;

    QComboBox *m_choixAffichage;
    QPushButton *m_about;

    enum affichage
    {
        pourcentage,
        pour255,
        pour1000
    };

    affichage isAffichage();
    double isPourcentage(double valeur);
    double isPour1000(double valeur);

};

#endif // DIALOG_H

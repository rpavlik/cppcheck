/*
 * Cppcheck - A tool for static C/C++ code analysis
 * Copyright (C) 2007-2011 Daniel Marjamäki and Cppcheck team.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PROJECTFILE_DIALOG_H
#define PROJECTFILE_DIALOG_H

#include <QDialog>
#include <QString>
#include <QStringList>

#include "ui_projectfile.h"

class ProjectFile;
class QWidget;
class QLineEdit;

/// @addtogroup GUI
/// @{


/**
* @brief A dialog for editing project file data.
*/
class ProjectFileDialog : public QDialog
{
    Q_OBJECT
public:
    ProjectFileDialog(const QString &path, QWidget *parent = 0);
    virtual ~ProjectFileDialog();

    /**
    * @brief Return project root path from the dialog control.
    * @return Project root path.
    */
    QString GetRootPath() const;

    /**
    * @brief Return include paths from the dialog control.
    * @return List of include paths.
    */
    QStringList GetIncludePaths() const;

    /**
    * @brief Return define names from the dialog control.
    * @return List of define names.
    */
    QStringList GetDefines() const;

    /**
    * @brief Return check paths from the dialog control.
    * @return List of check paths.
    */
    QStringList GetPaths() const;

    /**
    * @brief Return ignored paths from the dialog control.
    * @return List of ignored paths.
    */
    QStringList GetIgnorePaths() const;

    /**
    * @brief Set project root path to dialog control.
    * @param root Project root path to set to dialog control.
    */
    void SetRootPath(const QString &root);

    /**
    * @brief Set include paths to dialog control.
    * @param includes List of include paths to set to dialog control.
    */
    void SetIncludepaths(const QStringList &includes);

    /**
    * @brief Set define names to dialog control.
    * @param defines List of define names to set to dialog control.
    */
    void SetDefines(const QStringList &defines);

    /**
    * @brief Set check paths to dialog control.
    * @param paths List of path names to set to dialog control.
    */
    void SetPaths(const QStringList &paths);

    /**
    * @brief Set ignored paths to dialog control.
    * @param paths List of path names to set to dialog control.
    */
    void SetIgnorePaths(const QStringList &paths);

protected slots:
    /**
    * @brief Browse for include directory.
    * Allow user to add new include directory to the list.
    */
    void AddIncludeDir();

    /**
    * @brief Add new path to check.
    */
    void AddPath();

    /**
    * @brief Remove include directory from the list.
    */
    void RemoveIncludeDir();

    /**
    * @brief Edit include directory in the list.
    */
    void EditIncludeDir();

    /**
    * @brief Edit path in the list.
    */
    void EditPath();

    /**
    * @brief Remove path from the list.
    */
    void RemovePath();

    /**
    * @brief Add new path to ignore.
    */
    void AddIgnorePath();

    /**
    * @brief Edit ignored path in the list.
    */
    void EditIgnorePath();

    /**
    * @brief Remove ignored path from the list.
    */
    void RemoveIgnorePath();

protected:

    /**
     * @brief Save dialog settings.
     */
    void LoadSettings();

    /**
     * @brief Load dialog settings.
     */
    void SaveSettings();

    /**
    * @brief Add new indlude directory.
    * @param dir Directory to add.
    */
    void AddIncludeDir(const QString &dir);

    /**
    * @brief Add new path to check.
    * @param path Path to add.
    */
    void AddPath(const QString &path);

    /**
    * @brief Add new path to ignore list.
    * @param path Path to add.
    */
    void AddIgnorePath(const QString &path);

private:
    Ui::ProjectFile mUI;

    /**
     * @brief Projectfile path.
     */
    QString mFilePath;
};

/// @}
#endif // PROJECTFILE_DIALOG_H

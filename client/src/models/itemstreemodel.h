/*
  This file is part of FatCRM, a desktop application for SugarCRM written by KDAB.

  Copyright (C) 2015-2017 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Authors: David Faure <david.faure@kdab.com>
           Michel Boyer de la Giroday <michel.giroday@kdab.com>
           Kevin Krammer <kevin.krammer@kdab.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ITEMSTREEMODEL_H
#define ITEMSTREEMODEL_H

#include "enums.h"
#include "accountrepository.h"

#include <Akonadi/EntityTreeModel>

namespace KABC { class Addressee; }

/**
 * A model for sugar items.
 * This class provides a model for displaying the sugar items.
 *
 */
class ItemsTreeModel : public Akonadi::EntityTreeModel
{
    Q_OBJECT

public:
    /**
     * Describes the columns that can be shown by the model.
     * Some of them are used by many object types.
     */
    enum ColumnType {
        Name,
        PostalCode,
        City,
        Country,
        Description,
        Phone,
        Email,
        CreationDate,
        CreatedBy,
        CampaignName,
        Status,
        Street,
        Type,
        EndDate,
        User,
        FullName,
        Title,
        Organization,
        PreferredEmail,
        PhoneWork,
        PhoneMobile,
        LeadName,
        LeadAccountName,
        LeadEmail,
        LeadStatus,
        LeadUser,
        OpportunityName,
        OpportunityAccountName,
        OpportunitySize,
        SalesStage,
        Amount,
        NextStep,
        NextStepDate,
        LastModifiedDate,
        AssignedTo,
        OpportunityPriority
    };

    Q_ENUMS(ColumnType)

    /**
     * Describes a list of columns of the items tree model.
     */
    typedef QList<ColumnType> ColumnTypes;

    /**
     * Creates a new items tree model.
     *
     * param: monitor The ChangeRecorder whose entities should be
     * represented in the model.
     * param: parent The parent object.
     */
    explicit ItemsTreeModel(DetailsType type, Akonadi::ChangeRecorder *monitor, QObject *parent = 0);

    ~ItemsTreeModel() override;

    ColumnTypes columnTypes() const; // all available column types
    ColumnTypes defaultVisibleColumns() const; // the column types that should be initially visible
    QString columnName(int column) const;

    static QString columnNameFromType(ColumnType col);
    static ColumnType columnTypeFromName(const QString &name);
    static ColumnTypes columnTypes(DetailsType type);

    QVariant entityData(const Akonadi::Item &item, int column, int role = Qt::DisplayRole) const override;
    QVariant entityData(const Akonadi::Collection &collection, int column, int role = Qt::DisplayRole) const override;
    QVariant entityHeaderData(int section, Qt::Orientation orientation, int role, HeaderGroup headerGroup) const override;
    int entityColumnCount(HeaderGroup headerGroup) const override;

    static QString countryForContact(const KABC::Addressee &addressee);

private Q_SLOTS:
    void slotAccountModified(const QString &accountId, const QVector<AccountRepository::Field> &changedFields);
    void slotAccountsLoaded();

private:
    QVariant accountData(const Akonadi::Item &item, int column, int role) const;
    QVariant campaignData(const Akonadi::Item &item, int column, int role) const;
    QVariant contactData(const Akonadi::Item &item, int column, int role) const;
    QVariant leadData(const Akonadi::Item &item, int column, int role) const;
    QVariant opportunityData(const Akonadi::Item &item, int column, int role) const;
    QVariant accountToolTip(const Akonadi::Item &item) const;
    QVariant opportunityToolTip(const Akonadi::Item &item) const;
    QString columnTitle(ColumnType col) const;

private:
    class Private;
    Private *const d;
    DetailsType mType;
};

#endif /* ITEMSTREEMODEL_H */

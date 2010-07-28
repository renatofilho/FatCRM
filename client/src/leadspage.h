#ifndef LEADSPAGE_H
#define LEADSPAGE_H

#include "ui_leadspage.h"

#include <akonadi/collection.h>
#include <akonadi/entitytreemodel.h>

#include <QtGui/QWidget>

namespace Akonadi
{
    class ChangeRecorder;
    class Item;
    class ItemModel;
}

class KJob;
class QModelIndex;

class LeadsPage : public QWidget
{
    Q_OBJECT
public:
    explicit LeadsPage( QWidget *parent = 0 );

    ~LeadsPage();

    void addLeadsData();

Q_SIGNALS:
    void statusMessage( const QString& );

public Q_SLOTS:
    void syncronize();

private:
    void initialize();
    void setupCachePolicy();
    void leadChanged( const Akonadi::Item &item );
    bool proceedIsOk();

    Akonadi::ChangeRecorder *mChangeRecorder;
    Akonadi::Collection mLeadsCollection;
    QModelIndex mCurrentIndex;
    Ui_LeadsPage mUi;

private Q_SLOTS:
    void slotResourceSelectionChanged( const QByteArray &identifier );
    void slotCollectionFetchResult( KJob *job );
    void slotLeadClicked( const QModelIndex& index );
    void slotNewLeadClicked();
    void slotAddLead();
    void slotModifyLead();
    void slotRemoveLead();
    void slotSetCurrent( const QModelIndex&,int,int );
    void cachePolicyJobCompleted( KJob* );
    void slotUpdateItemDetails( const QModelIndex&, const QModelIndex& );
    void slotSetItem();
    void slotResetSearch();
};


#endif /* LEADSPAGE_H */


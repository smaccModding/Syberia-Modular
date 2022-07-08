modded class IngameHud
{	
	void InitNotifierWidget(int id, ref Widget baseWidget, string name)
	{
		ref Widget notifierWidget = baseWidget.FindAnyWidget(name);
		baseWidget.RemoveChild(notifierWidget);
		
		m_StatesWidgetNames.Set( id, name );
		
		Widget defaultNotifiersPanel = m_HudPanelWidget.FindAnyWidget("NotifiersPanel");
		Widget defaultBadgesSpacer = m_HudPanelWidget.FindAnyWidget("BadgesSpacer");
		Widget defaultBadgesPanel = m_HudPanelWidget.FindAnyWidget("BadgesPanel");
		
		float widgetOffsetX;
		float widgetWidth;
		
		float x, y, x2;
		defaultNotifiersPanel.FindAnyWidget("Thirsty").GetPos(x, y);
		defaultNotifiersPanel.FindAnyWidget("Hungry").GetPos(x2, y);
		widgetWidth = x - x2;
		widgetOffsetX = x + widgetWidth;
		
		defaultNotifiersPanel.GetSize(x, y);
		defaultNotifiersPanel.SetSize(x + widgetWidth, y);
		
		defaultNotifiersPanel.AddChild(notifierWidget);
		notifierWidget.SetPos(widgetOffsetX, 0);
		notifierWidget.Show(true);
		
		defaultBadgesSpacer.GetPos(x, y);
		defaultBadgesSpacer.SetPos(x + widgetWidth, y);
		
		defaultBadgesPanel.GetPos(x, y);
		defaultBadgesPanel.SetPos(x + widgetWidth, y);
		
		ref ImageWidget imagew = notifierWidget.FindAnyWidget("Icon" + name); 
		m_StatesWidgets.Set(id, imagew);
		for ( int i = 0; i < 5; i++ )
		{
			imagew.LoadImageFile( i, "SyberiaScripts/data/gui/" + name + "/icon" + i + ".paa");
		}		
	}
	
	void InitBadgetWidget(int id, ref Widget baseWidget, string name)
	{
		ref Widget badge_widget = baseWidget.FindAnyWidget(name);
		baseWidget.RemoveChild(badge_widget);
		m_Badges.AddChild(badge_widget);
		
		m_BadgesWidgetNames.Set( id, name );
		m_BadgesWidgets.Set( id, badge_widget );
		badge_widget.Show( false );
		m_BadgesWidgetDisplay.Set( id, 0 );
	}
	
	override void DisplayBadge( int key, int value )
	{
		if (key == NTFKEY_PILLS)
		{
			// Disable vanilla pills
			value = 0;
		}
		
		if (m_BadgesWidgetDisplay.Get( key ) == value)
		{
			return;
		}
		
		super.DisplayBadge(key, value);
		
		string badge_name = m_BadgesWidgetNames.Get( key );
		TextWidget w_count = TextWidget.Cast( m_Badges.FindAnyWidget( badge_name + "Count" ) );
		if (w_count)
		{
			string badgeText = "";
			bool isLeveled = false;
			
			for (int i = 0; i < LEVELED_NTFKEY_BADGES_COUNT; i++)
			{
				if (LEVELED_NTFKEY_BADGES[i] == key)
				{
					isLeveled = true;
					break;
				}
			}
			
			if (isLeveled)
			{
				if (value == 0) badgeText = "";
				else if (value == 1) badgeText = "I";
				else if (value == 2) badgeText = "II";
				else if (value == 3) badgeText = "III";
				else if (value == 4) badgeText = "IV";
				else if (value == 5) badgeText = "V";
			}
			else
			{
				badgeText = value.ToString();
			}
			
			w_count.SetText( badgeText );
		}
	}
}